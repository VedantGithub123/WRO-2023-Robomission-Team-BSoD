void zone5(){ // This zone moves the ships and ends in the mooring area

	// Move onto the line

	movePID(40,-0.5,0,0,0.12,-180,70,-0.5,0,0,0.06,0);

	movePID(70,-0.5,0,0,0.12,0,70,-0.5,0,0,0.12,280);

	movePID(40,-0.5,0,0,0.12,-640,70,-0.5,0,0,0.06,0);

	setMotorSpeed(left, -20);
	setMotorSpeed(right, 20);

	waitUntil(getColorReflected(CS2)>midpoint2+15);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	movePID(50,-0.5,0,0,0.06,-480,50,-0.5,0,0,0.06,480);

	movePID(50,-0.5,0,0,0.06,450,50,-0.5,0,0,0.06,0);

	setMotorSpeed(left, 20);

	waitUntil(getColorReflected(CS2)>midpoint2+15);

	waitUntil(getColorReflected(CS2)<midpoint2-15);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	// Line follow to the open ocean
	lfPID(0, -50, midpoint2, 0.4, 0, 0, 1000, 2);
	lfPID(0, -70, midpoint2, 0.8, 0, 0, 2000, 2);

	resetMotorEncoder(left);
	resetMotorEncoder(right);


	// Align the robot so that it is straight

	setMotorSpeed(left, -30);
	setMotorSpeed(right, 30);

	clearTimer(T4);
	waitUntil(time1(T4)>1000);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	movePID(60,-0.4,0,0,0.06,130,60,-0.4,0,0,0.06,-130);

	lsPID(2, midpoint2, 0.33, 0, 0, 3, midpoint3, -0.33, 0, 0, 800);


	// Turn until the sensor sees white and then a bit more

	setMotorSpeed(right, 30);
	sleep(500);

	waitUntil(getColorReflected(CS3)<midpoint2-15);
	//setMotorSpeed(right, 50);
	waitUntil(getColorReflected(CS3)>midpoint2+15);

	resetMotorEncoder(right);
	waitUntil(getMotorEncoder(right)>105);
	setMotorSpeed(right, 0);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(60,-0.4,0,0,0.06,-130,60,-0.4,0,0,0.06,130);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);


	setMotorSpeed(left, 20);
	waitUntil(getMotorEncoder(left)>120);
	setMotorSpeed(left, 0);

	setMotorSpeed(right, -20);
	waitUntil(getMotorEncoder(right)<-160);
	setMotorSpeed(right, 0);

	lfPID(1, 10, midpoint1, -0.25, 0, 0, 5000, 1);


	// Move to the ending position

	setMotorSpeed(left, -20);
	setMotorSpeed(right, 20);
	sleep(500);

	clearTimer(T4);
	while (time1(T4)<1000){
		setMotorSpeed(left, -1*min((time1(T4)*2), 100));
		setMotorSpeed(right, min((time1(T4)*2), 100));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	setMotorSpeed(grab, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
}
