#ifndef _mpu6050_h
#define _mpu6050_h

#include <wiringPi.h>
#include <wiringPiI2C.h>

#define Sample_rate			25
#define Config				26
#define Gyro_config			27
#define Acc_config			28
#define Interrupt			56
#define PWR_Managment 		107
#define Acc_X				59
#define Acc_Y				61
#define Acc_Z				63

int mpu;

void Init_6050(void){
	
	mpu = wiringPiI2CSetup(0x68);
	// register 25->28, 56, 107
	// sample_rate 500Hz
	wiringPiI2CWriteReg8(mpu,Sample_rate,15);
	// Khong su dung nguon xung ngoai, tat DLFP
	wiringPiI2CWriteReg8(mpu,Config,3);
	// gyro FS: +- 500o/s
	wiringPiI2CWriteReg8(mpu,Gyro_config,0x08);
	// acc FS: +- 8g
	wiringPiI2CWriteReg8(mpu,Acc_config,0x10);
	// mo interrupt cua data ready
	wiringPiI2CWriteReg8(mpu,Interrupt,1);
	// chon nguon xung GYro X
	wiringPiI2CWriteReg8(mpu,PWR_Managment,0x01);
	
}

#endif