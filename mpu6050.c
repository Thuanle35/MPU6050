#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "mpu6050.h"


int mpu;

int16_t read_sensor(unsigned char sensor) {
	int16_t high, low, data;
	high = wiringPiI2CReadReg8(mpu, Acc_X);
	low = wiringPiI2CReadReg8(mpu, Acc_X + 1);
	data = (high<<8) | low;
	return data;
}

int main(void)
{
	// thiet lap che do cho MPU
	Init_6050();
	while(1){
	// doc gia tri do
	float Ax = (float)read_sensor(Acc_X)/4096.0;
	float Ay = (float)read_sensor(Acc_Y)/4096.0;
	float Az = (float)read_sensor(Acc_Z)/4096.0;
	printf("Toa do Ax: %f, Toa do Ay: %f, Toa do Az: %f\n",Ax,Ay,Az);
	float pitch = atan2(Ax, sqrt(pow(Ay,2)+pow(Az,2)))*180/M_PI;
	float roll = atan2(Ay, sqrt(pow(Ax,2)+pow(Az,2)))*180/M_PI;
	printf("Gia tri cua pitch : %f va roll %f\n", pitch,roll);
	
	delay(1000);
	// doc nhiet do
	int16_t temp = wiringPiI2CReadReg8(mpu,65);
	temp = (temp<<8)|wiringPiI2CReadReg8(mpu,66);
	float T;
	T = temp/340.0+36.53;
	printf("Nhiet do: %f\n",T);
	delay(1000);
	
	
	}
	return 0;
}




