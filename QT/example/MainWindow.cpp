/***************************************************************************//**
 * @file example/MainWindow.cpp
 * @author  Marek M. Cel <marekcel@marekcel.pl>
 *
 * @section LICENSE
 *
 * Copyright (C) 2013 Marek M. Cel
 *
 * This file is part of QFlightInstruments. You can redistribute and modify it
 * under the terms of GNU General Public License as published by the Free
 * Software Foundation; either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * Further information about the GNU General Public License can also be found
 * on the world wide web at http://www.gnu.org.
 *
 * ---
 *
 * Copyright (C) 2013 Marek M. Cel
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/
#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP
#endif

////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <string.h>
#include <sstream>

#include <QLabel>
#include <QPushButton>
#include <QPixmap>


#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SerialPort.h"

#include <Windows.h>     //将该头文件放在上面会有奇怪的报错
#include <ctime>
////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////

WzSerialPort port;

////////////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    m_ui( new Ui::MainWindow ),

    m_timerId ( 0 ),
    m_steps   ( 0 ),

    m_realTime ( 0.0 )
{
    m_ui->setupUi( this );

    m_timerId  = startTimer( 0 );

    //初始化未连接界面
    image.load(":/qfi/images/pfd/align_pfd-1.png");

    //setgeometry的参数是根据父对象来定义的
    m_ui->labelerr->setGeometry(0,0,630,630);
    m_ui->labelerr->setPixmap(image.scaled(598,595,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    m_ui->labelerr->raise();

    QPushButton *button = (m_ui->pushButtonSerial) ;
    connect(button,QPushButton::pressed,this,MainWindow::openserial);
    //信号和槽函数的参数要对应，信号是void槽函数将不能有输入参数
    m_time.start();
}

////////////////////////////////////////////////////////////////////////////////

MainWindow::~MainWindow()
{
    cout << "Average time step: " << ( (double)m_realTime ) / ( (double)m_steps ) << " s" << endl;

    if ( m_timerId ) killTimer( m_timerId );

    if ( m_ui ) delete m_ui; m_ui = 0;
}

////////////////////////////////////////////////////////////////////////////////
void MainWindow::openserial()
{
    int port_no = m_ui->spinBox->value();
    string s = "COM";
    ostringstream oss;
    oss << s <<port_no;
    string portname = oss.str();
    char * port_name = &portname[0];
    port.open(port_name, 9600, 0, 8, 1 ,1);
    cout<<"port open  "<<port_no<<endl;

}

////////////////////////////////////////////////////////////////////////////////
int MainWindow::lostconnecterror(int loseconnectflag)
{
    if(loseconnectflag==0)
    {
        m_ui->label_18->setText("Lost Connect");

        m_ui->labelerr->show();
        m_ui->labelerr->setGeometry(0,0,m_ui->widgetPFD->width(),m_ui->widgetPFD->height());
        m_ui->labelerr->setPixmap(image.scaled(m_ui->widgetPFD->width(),m_ui->widgetPFD->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        m_ui->labelerr->setScaledContents(true);
        return 1;
    }
    else if(loseconnectflag==31)
    {
        m_ui->label_18->setText("Connected");
        m_ui->labelerr->hide();
        return 0;
    }
    else
        m_ui->label_18->setText("Wrong Data");

        m_ui->labelerr->show();
        m_ui->labelerr->setGeometry(0,0,m_ui->widgetPFD->width(),m_ui->widgetPFD->height());
        m_ui->labelerr->setPixmap(image.scaled(m_ui->widgetPFD->width(),m_ui->widgetPFD->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        m_ui->labelerr->setScaledContents(true);
        return 1;
}

////////////////////////////////////////////////////////////////////////////////
float climbRate =  0.0f;
float velocityX =  0.0f;
float velocityY =  0.0f;
float Realvelocity =  0.0f;
float last_altitude  =  0.0f;
////////////////////////////////////////////////////////////////////////////////
void MainWindow::timerEvent( QTimerEvent *event )
{
    /////////////////////////////////
    QMainWindow::timerEvent( event );
    /////////////////////////////////

    float timeStep = m_time.restart();

    m_realTime = m_realTime + timeStep / 1000.0f;

    float alpha     =  0.0f;
    float beta      =  0.0f;
    float roll      =  0.0f;
    float pitch     =  0.0f;
    float heading   =  0.0f;
    float slipSkid  =  0.0f;
    float turnRate  =  0.0f;
    float devH      =  0.0f;
    float devV      =  0.0f;
    float airspeed  =  0.0f;
    float altitude  =  0.0f;
    float pressure  = 28.0f;
//    float climbRate =  0.0f;
    float machNo    =  0.0f;
    //float adf       =  0.0f;
    float dme       =  0.0f;

    float aacx = 0.0f;
    float aacy = 0.0f;
    float aacz = 0.0f;
    float aac = 0.0f;

    float velocity  =  0.0f;

    char stralpha[10];
    char strbeta[10];
    char strroll[10];
    char strpitch[10];
    char strheading[10];
    char strslipSkid[10];
    char strturnRate[10];
    char strdevH[10];
    char strdevV[10];
    char strairspeed[10];
    char straltitude[10];
    char strpressure[10];
    char strclimbRate[10];
    char strmachNo[10];
    char strdme[10];

    if ( m_ui->pushButtonAuto->isChecked() )
    {
        char sendbuf[2];
        sendbuf[0]=0x0D;
        sendbuf[1]=0x0A;
        port.send(sendbuf, 2);

        Sleep(50);

        unsigned char buf[31];

        int numcount = 0;

        memset(buf, 0,31);
        numcount = port.receive(buf, 31);

        //测试打印信息，relsase时注释
//        cout<<"port count"<<numcount<<endl;
//        cout<<buf<<endl;

        int ErrorFlag = lostconnecterror(numcount);

        if((ErrorFlag==0)&&(buf[0]==0x88))
        {

        pitch = ((signed short)(buf[20+3]*256+buf[21+3]))/100.0f;
        roll = ((signed short)(buf[18+3]*256+buf[19+3]))/100.0f;
        heading = ((signed short)(buf[22+3]*256+buf[23+3]))/10.0f;

        if(pitch>=20)
            alpha = 20;
        else if(pitch<=-20)
            alpha = -20;
        else
            alpha = pitch;

        turnRate = ((signed short)(buf[10+3]*256+buf[11+3]))/16.4f;

        altitude = (unsigned short)(buf[14+3]*256+buf[15+3]);

        climbRate = (altitude - last_altitude)/(timeStep/1000.0f)*60;
        last_altitude = altitude;

        pressure = ((signed short)(buf[12+3]*256+buf[13+3]))/100.0f;

        //加速度的单位是m/s2,z轴要减去一个g
        aacx = ((signed short)(buf[0+3]*256+buf[1+3]))/16384.0f;
        aacy = ((signed short)(buf[2+3]*256+buf[3+3]))/16384.0f;
        aacz = ((signed short)(buf[4+3]*256+buf[5+3]))/16384.0f;

        aac = sqrt(aacx*aacx+aacy*aacy+aacz*aacz)-1;

//        if ((aacz-1>0.02)|(aacz-1<-0.02))
//        climbRate -=  ((aacz-1) * timeStep / 1000.0f)*60*3.28f;

        if ((aacx>0.05)|(aacx<-0.05))
        velocityX -=  (aacx * timeStep / 1000.0f)*10;

        if ((aacy>0.05)|(aacy<-0.05))
        velocityY -=  (aac * timeStep / 1000.0f)*10;

        if ((aac>0.05)|(aac<-0.05))
        Realvelocity += (aac * timeStep / 1000.0f);   //速度单位是m/s


        velocity = sqrt(velocityX*velocityX+ velocityY* velocityY);

        airspeed = fabs(Realvelocity)*60/1852.0f;   //单位转换为海里/小时
        machNo = fabs(Realvelocity)*3.6/1192.9f;    //速度转换为马赫数


        if (velocity !=0)
        beta = acos((velocityX/velocity));

        sprintf(stralpha,    "%.2lf", alpha          );
        sprintf(strbeta,     "%.2lf", beta           );
        sprintf(strroll,     "%.2lf", roll           );
        sprintf(strpitch,    "%.2lf", pitch          );
        sprintf(strslipSkid, "%.2lf", slipSkid       );
        sprintf(strturnRate, "%.2lf", turnRate       );
        sprintf(strdevH,     "%.2lf", devH           );
        sprintf(strdevV,     "%.2lf", devV           );
        sprintf(strheading,  "%.2lf", heading        );
        sprintf(strairspeed, "%.2lf", airspeed       );
        sprintf(strmachNo,   "%.2lf", machNo         );
        sprintf(straltitude, "%.2lf", altitude       );
        sprintf(strpressure, "%.2lf", pressure       );
        sprintf(strclimbRate,"%.2lf", climbRate   );
        sprintf(strdme,      "%.2lf", dme            );


        m_ui->labelAlpha ->setText(stralpha     );
        m_ui->labelBeta  ->setText(strbeta      );
        m_ui->labelRoll  ->setText(strroll      );
        m_ui->labelPitch ->setText(strpitch     );
        m_ui->labelSlip  ->setText(strslipSkid  );
        m_ui->labelTurn  ->setText(strturnRate  );
        m_ui->labelDevH  ->setText(strdevH      );
        m_ui->labelDevV  ->setText(strdevV      );
        m_ui->labelHead  ->setText(strheading   );
        m_ui->labelSpeed ->setText(strairspeed  );
        m_ui->labelMach  ->setText(strmachNo    );
        m_ui->labelAlt   ->setText(straltitude  );
        m_ui->labelPress ->setText(strpressure  );
        m_ui->labelClimb ->setText(strclimbRate );
        //m_ui->spinBoxADF   ->setValue( adf       );
        m_ui->labelDME   ->setText(strdme      );
        }
    }
    else
    {
        QByteArray ba = m_ui->labelAlpha->text().toLatin1();
        strcpy(stralpha,ba.data());

        ba  = m_ui->labelBeta->text().toLatin1();
        strcpy(strbeta ,ba.data());

        ba  = m_ui->labelRoll->text().toLatin1();
        strcpy(strroll, ba.data());

        ba = m_ui->labelPitch->text().toLatin1();
        strcpy(strpitch,ba.data());

        ba = m_ui->labelHead->text().toLatin1();
        strcpy(strheading,ba.data());

        ba = m_ui->labelSlip->text().toLatin1();
        strcpy(strslipSkid,ba.data());

        ba = m_ui->labelTurn->text().toLatin1();
        strcpy(strturnRate, ba.data());

        ba = m_ui->labelDevH->text().toLatin1();
        strcpy(strdevH,ba.data());

        ba = m_ui->labelDevV->text().toLatin1();
        strcpy(strdevV,ba.data());

        ba= m_ui->labelSpeed->text().toLatin1();
        strcpy(strairspeed,ba.data());

        ba = m_ui->labelPress->text().toLatin1();
        strcpy(strpressure,ba.data());

        ba = m_ui->labelAlt->text().toLatin1();
        strcpy(straltitude,ba.data());

        ba = m_ui->labelClimb->text().toLatin1();
        strcpy(strclimbRate,ba.data());

        ba = m_ui->labelMach->text().toLatin1();
        strcpy(strmachNo,ba.data());

        ba = m_ui->labelDME->text().toLatin1();
        strcpy(strdme,ba.data());

        sscanf(stralpha,      "%f",  &alpha     );
        sscanf(strbeta,       "%f",  &beta      );
        sscanf(strroll,       "%f",  &roll      );
        sscanf(strpitch,      "%f",  &pitch     );
        sscanf(strheading,    "%f",  &heading   );
        sscanf(strslipSkid,   "%f",  &slipSkid );
        sscanf(strturnRate,   "%f",  &turnRate  );
        sscanf(strdevH,       "%f",  &devH      );
        sscanf(strdevV,       "%f",  &devV      );
        sscanf(strairspeed,   "%f",  &airspeed  );
        sscanf(strpressure,   "%f",  &pressure  );
        sscanf(straltitude,   "%f",  &altitude  );
        sscanf(strclimbRate,  "%f",  &climbRate );
        sscanf(strmachNo,     "%f",  &machNo    );
        sscanf(strdme,        "%f",  &dme       );

    }

    m_ui->widgetPFD->setFlightPathMarker ( alpha, beta );
    m_ui->widgetPFD->setRoll          ( roll     );
    m_ui->widgetPFD->setPitch         ( pitch     );
    m_ui->widgetPFD->setSlipSkid      ( slipSkid  );
    m_ui->widgetPFD->setTurnRate      ( turnRate / 60.0f );
    m_ui->widgetPFD->setDevH          ( devH      );
    m_ui->widgetPFD->setDevV          ( devV      );
    m_ui->widgetPFD->setHeading       ( heading   );
    m_ui->widgetPFD->setAirspeed      ( airspeed  );
    m_ui->widgetPFD->setMachNo        ( machNo    );
    m_ui->widgetPFD->setAltitude      ( altitude  );
    m_ui->widgetPFD->setPressure      ( pressure  );
    m_ui->widgetPFD->setClimbRate     ( climbRate / 100.0f );
    m_ui->widgetPFD->setIdentifier    ( "ILAX" , true );
    m_ui->widgetPFD->setDistance      ( dme    , true );

    m_ui->widgetPFD->update();


    m_steps++;
}


