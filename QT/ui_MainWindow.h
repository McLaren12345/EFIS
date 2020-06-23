/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "WidgetPFD.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_13;
    QLabel *labelDME;
    QLabel *labelPress;
    QLabel *labelClimb;
    QLabel *labelDevV;
    QLabel *labelMach;
    QLabel *labelAlt;
    QLabel *labelSpeed;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_4;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_16;
    QPushButton *pushButtonAuto;
    QLabel *labelBeta;
    QLabel *labelHead;
    QLabel *labelTurn;
    QLabel *labelRoll;
    QLabel *labelDevH;
    QLabel *labelSlip;
    QLabel *labelAlpha;
    QLabel *labelPitch;
    QPushButton *pushButtonSerial;
    QSpinBox *spinBox;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_18;
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    WidgetPFD *widgetPFD;
    QLabel *labelerr;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMaximumSize(QSize(300, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 0, 0, 1, 1);

        labelDME = new QLabel(frame);
        labelDME->setObjectName(QStringLiteral("labelDME"));

        gridLayout->addWidget(labelDME, 14, 1, 1, 1);

        labelPress = new QLabel(frame);
        labelPress->setObjectName(QStringLiteral("labelPress"));

        gridLayout->addWidget(labelPress, 12, 1, 1, 1);

        labelClimb = new QLabel(frame);
        labelClimb->setObjectName(QStringLiteral("labelClimb"));

        gridLayout->addWidget(labelClimb, 13, 1, 1, 1);

        labelDevV = new QLabel(frame);
        labelDevV->setObjectName(QStringLiteral("labelDevV"));

        gridLayout->addWidget(labelDevV, 8, 1, 1, 1);

        labelMach = new QLabel(frame);
        labelMach->setObjectName(QStringLiteral("labelMach"));

        gridLayout->addWidget(labelMach, 10, 1, 1, 1);

        labelAlt = new QLabel(frame);
        labelAlt->setObjectName(QStringLiteral("labelAlt"));

        gridLayout->addWidget(labelAlt, 11, 1, 1, 1);

        labelSpeed = new QLabel(frame);
        labelSpeed->setObjectName(QStringLiteral("labelSpeed"));

        gridLayout->addWidget(labelSpeed, 9, 1, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 9, 0, 1, 1);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 11, 0, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 13, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 10, 0, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 8, 0, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        line = new QFrame(frame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 15, 0, 1, 2);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 12, 0, 1, 1);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 1, 0, 1, 1);

        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_16, 14, 0, 1, 1);

        pushButtonAuto = new QPushButton(frame);
        pushButtonAuto->setObjectName(QStringLiteral("pushButtonAuto"));
        pushButtonAuto->setCheckable(true);

        gridLayout->addWidget(pushButtonAuto, 16, 0, 1, 1);

        labelBeta = new QLabel(frame);
        labelBeta->setObjectName(QStringLiteral("labelBeta"));
        labelBeta->setScaledContents(false);

        gridLayout->addWidget(labelBeta, 1, 1, 1, 1);

        labelHead = new QLabel(frame);
        labelHead->setObjectName(QStringLiteral("labelHead"));

        gridLayout->addWidget(labelHead, 4, 1, 1, 1);

        labelTurn = new QLabel(frame);
        labelTurn->setObjectName(QStringLiteral("labelTurn"));

        gridLayout->addWidget(labelTurn, 6, 1, 1, 1);

        labelRoll = new QLabel(frame);
        labelRoll->setObjectName(QStringLiteral("labelRoll"));

        gridLayout->addWidget(labelRoll, 2, 1, 1, 1);

        labelDevH = new QLabel(frame);
        labelDevH->setObjectName(QStringLiteral("labelDevH"));

        gridLayout->addWidget(labelDevH, 7, 1, 1, 1);

        labelSlip = new QLabel(frame);
        labelSlip->setObjectName(QStringLiteral("labelSlip"));

        gridLayout->addWidget(labelSlip, 5, 1, 1, 1);

        labelAlpha = new QLabel(frame);
        labelAlpha->setObjectName(QStringLiteral("labelAlpha"));
        labelAlpha->setFrameShape(QFrame::NoFrame);
        labelAlpha->setFrameShadow(QFrame::Sunken);
        labelAlpha->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(labelAlpha, 0, 1, 1, 1);

        labelPitch = new QLabel(frame);
        labelPitch->setObjectName(QStringLiteral("labelPitch"));

        gridLayout->addWidget(labelPitch, 3, 1, 1, 1);

        pushButtonSerial = new QPushButton(frame);
        pushButtonSerial->setObjectName(QStringLiteral("pushButtonSerial"));

        gridLayout->addWidget(pushButtonSerial, 16, 1, 1, 1);

        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setPrefix(QStringLiteral(""));
        spinBox->setMinimum(1);
        spinBox->setValue(1);

        gridLayout->addWidget(spinBox, 17, 1, 1, 1);

        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_15, 17, 0, 1, 1);

        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_17, 18, 0, 1, 1);

        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 18, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        splitter->addWidget(frame);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widgetPFD = new WidgetPFD(frame_2);
        widgetPFD->setObjectName(QStringLiteral("widgetPFD"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetPFD->sizePolicy().hasHeightForWidth());
        widgetPFD->setSizePolicy(sizePolicy1);
        labelerr = new QLabel(widgetPFD);
        labelerr->setObjectName(QStringLiteral("labelerr"));
        labelerr->setGeometry(QRect(110, 160, 55, 16));

        gridLayout_2->addWidget(widgetPFD, 0, 0, 2, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        splitter->addWidget(frame_2);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QFlightInstruments Example", 0));
        label_13->setText(QApplication::translate("MainWindow", "Angle of Attack [deg]:", 0));
        labelDME->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelPress->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelClimb->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelDevV->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelMach->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelAlt->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelSpeed->setText(QApplication::translate("MainWindow", "0.0", 0));
        label_6->setText(QApplication::translate("MainWindow", "Horizontal Deviation [-]:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Airspeed [kts]:", 0));
        label_9->setText(QApplication::translate("MainWindow", "Altitude [ft]:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Climb Rate [ft/min]:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Heading [deg]:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Mach Number [-]:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Turn Rate [deg/s]:", 0));
        label->setText(QApplication::translate("MainWindow", "Roll [deg]:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Vertical Deviation [-]:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Sideslip [-]:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Pitch [deg]:", 0));
        label_12->setText(QApplication::translate("MainWindow", "Pressure [inHg]:", 0));
        label_14->setText(QApplication::translate("MainWindow", "Angle of Sideslip [deg]:", 0));
        label_16->setText(QApplication::translate("MainWindow", "DME distance [nm]:", 0));
        pushButtonAuto->setText(QApplication::translate("MainWindow", "CONNECT DEVICE", 0));
        labelBeta->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelHead->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelTurn->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelRoll->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelDevH->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelSlip->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelAlpha->setText(QApplication::translate("MainWindow", "0.0", 0));
        labelPitch->setText(QApplication::translate("MainWindow", "0.0", 0));
        pushButtonSerial->setText(QApplication::translate("MainWindow", "OPEN SERIAL", 0));
        label_15->setText(QApplication::translate("MainWindow", "Serial Port NO\357\274\232COM", 0));
        label_17->setText(QApplication::translate("MainWindow", "Current State:", 0));
        label_18->setText(QApplication::translate("MainWindow", "Not Connect", 0));
        labelerr->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
