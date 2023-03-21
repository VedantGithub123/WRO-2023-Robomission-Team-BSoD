#pragma config(Sensor, S1,     CS1,            sensorEV3_Color)
#pragma config(Sensor, S2,     CS2,            sensorEV3_Color)
#pragma config(Sensor, S3,     CS3,            sensorEV3_Color)
#pragma config(Motor,  motorA,          grab,          tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Medium, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Medium, PIDControl, driveRight, encoder)
#pragma config(Motor,  motorD,          arm,           tmotorEV3_Medium, PIDControl)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-colour-v2.h" // Includes the code for the hitechnic color sensor
tHTCS2 HCS1; // Creates a hitechnic sensor object
int blocks[2] = {1, 2}; // Creates the default block options
int midpoint1 = 35; // Globally defines the midpoint for the color sensor in port 1
int midpoint2 = 45; // Globally defines the midpoint for the color sensor in port 2
int midpoint3 = 40; // Globally defines the midpoint for the color sensor in port 3

// SLOW CODE:
//#include "functions.c"
//#include "zone1.c" // Pushes ship, senses blocks, goes to cargo area
//#include "zone2.c" // Picks up and puts blocks on the big ship and goes back to the cargo area
//#include "zone3.c" // Picks up and puts blocks on the small ship
//#include "zone4.c" // Moves the small ship to the line and grabs the big ship
//#include "zone5.c" // Brings ships to the open ocean area, puts red cargo on the crane, end in harbour area

// FAST CODE:
#include "sensing_functions.c" // Contains all the functions for sensing
#include "misc_functions.c" // Contains all the miscellaneous functions
#include "movement_functions.c" // Contains all the movement functions
#include "zone1_2.c" // Pushes ship, senses blocks, goes to cargo area
#include "zone2_2.c" // Picks up and puts blocks on the big ship and goes back to the cargo area
#include "zone3_2.c" // Picks up and puts blocks on the small ship
#include "zone4_2.c" // Moves the small ship to the line and grabs the big ship
#include "zone5_2.c" // Brings ships to the open ocean area, puts red cargo on the crane, end in harbour area

task main()
{

	/* Reference Notes:
	 		- 543 degrees is a 90 degree one motor turn
		 	- 271 degrees is a 90 degree two motor turn
 	  	- 360 degrees is about 20cm
	*/


	clearTimer(T3); // Clears the timer to time the run


	initSensor(&HCS1, S4); // Assigns port 4 to the hitechnic sensor object


	// Resets motors
	resetMotorEncoder(left);
	resetMotorEncoder(right);


	// Calls all zones
	zone1();
	zone2();
	zone3();
	zone4();
	zone5();


	// Shows the time on the robot and on the debug stream
	displayCenteredBigTextLine(5, "%d", time100(T3));
	clearDebugStream();
  writeDebugStream("%d", time100(T3));


  // Plays good sound if in time, plays bad sound if overtime
	if (time100(T3)>1200){
		playSound(soundDownwardTones);
	}else{
		playSound(soundUpwardTones);
	}
  sleep(10000);

}
