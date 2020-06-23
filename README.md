# EFIS
### Introduction
A STM32 based Primary Flight Display with QT based PC software indicator. Contain PCB files, STM32 project files, QT project files and 3D print models.

本项目为基于STM32的微型姿态仪，包含PCB文件，STM32工程文件，QT工程文件与3D打印外壳文件。

采用陀螺仪传感器MPU6050，气压式高度计BMP180，程序可以显示模块当前的六轴传感器数据与海拔高度，空速与垂直速度等采用模拟积分方法计算求得(也就是惯性导航)。BMP180气压数据采用一阶卡尔曼滤波方法进行平滑。通讯采用NRF21L01无线模块传输，PCB中未画出，仅保留了与模块的接口。

QT部分基于开源项目修改；https://sourceforge.net/projects/qfi/

### Images
![image1](https://github.com/McLaren12345/EFIS/blob/master/Images/IMG_1602.JPG)
![image2](https://github.com/McLaren12345/EFIS/blob/master/Images/IMG_1604.JPG)
![image3](https://github.com/McLaren12345/EFIS/blob/master/Images/IMG_1610.JPG)
![image4](https://github.com/McLaren12345/EFIS/blob/master/Images/IMG_1617.JPG)
