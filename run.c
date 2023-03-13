#pragma config(Sensor, S1,     GS1,            sensorEV3_Gyro)
#pragma config(Sensor, S2,     CS2,            sensorEV3_Color)
#pragma config(Sensor, S3,     CS3,            sensorEV3_Color)
#pragma config(Motor,  motorA,          grab,          tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Medium, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Medium, PIDControl, driveRight, encoder)
#pragma config(Motor,  motorD,          arm,           tmotorEV3_Medium, PIDControl)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-colour-v2.h"
tHTCS2 HCS1;
int blocks[2] = {1, 2};

#include "functions.c"
#include "zone1.c"
#include "zone2.c"
#include "zone3.c"
#include "zone4.c"
#include "zone5.c"

task main()
{

	clearTimer(T3);
	initSensor(&HCS1, S4);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	zone1();
	zone2();
	zone3();
	zone4();
	zone5();
	displayCenteredBigTextLine(5, "%d", time100(T3));
	if (time100(T3)>1200){
		playSound(soundDownwardTones);
	}else{
		playSound(soundUpwardTones);
	}
  sleep(10000);

}
