#ifndef _BMP180_H_
#define _BMP180_H_

#include "mpuiic.h"

typedef struct __BMP180
{
    short AC1;
    short AC2;
    short AC3;
    unsigned short AC4;
    unsigned short AC5;
    unsigned short AC6;
    short B1;
    short B2;
    short MB;
    short MC;
    short MD;
    long UT;
    long UP;
    long X1;
    long X2;
    long X3;
    long B3;
    unsigned long B4;
    long B5;
    long B6;
    long B7;
    long p;
    long Temp;
    float altitude;
		int pressure_inHg;
		int inchALT;
}_bmp180;

extern _bmp180 bmp180;

void BMP_Init(void);
uint8_t BMP_ReadOneByte(uint8_t ReadAddr);
void BMP_WriteOneByte(uint8_t WriteAddr,uint8_t DataToWrite);
short BMP_ReadTwoByte(uint8_t ReadAddr);
void BMP_ReadCalibrationData(void);
long BMP_Read_UT(void);
long BMP_Read_UP(void);
void BMP_UncompemstatedToTrue(void);

#endif
