void zone4(){ // This zone grabs up the ships

	// Gets into position to grab the small ship
	movePID(50,-0.5,0,0,0.06,35,50,-0.5,0,0,0.06,-35);

	movePID(50,-0.5,0,0,0.06,0,80,-0.8,0,0,0.1,530);

	movePID(50,-0.5,0,0,0.1,540,50,-0.5,0,0,0.1,540);

	movePID(50,-0.5,0,0,0.06,-200,50,-0.5,0,0,0.06,200);


	// Grabs and brings the small ship to the line

	setMotorSpeed(grab, 100);

	sleep(500);

	setMotorSpeed(grab, 20);

	movePID(70,-0.4,0,0,0.06,700,70,-0.4,0,0,0.06,-700);

	setMotorSpeed(grab, -100);
	waitUntil(getMotorEncoder(grab)<=0);

	setMotorSpeed(grab, 0);
	resetMotorEncoder(grab);


	// Get into position to grab the big ship

	movePID(60,-0.2,0,0,0.05,575,30,-0.9,0,0,0.06,0);

	movePID(40,-0.5,0,0,0.06,770,40,-0.5,0,0,0.06,-770);


	// Activate the mechanical AND gate

	setMotorSpeed(arm, 25);
	setMotorSpeed(grab, 25);
	sleep(700);

	setMotorSpeed(arm, -85);
	setMotorSpeed(grab, -85);
	sleep(700);

	setMotorSpeed(arm, 0);
	setMotorSpeed(grab, 0);

	stopTask(releaseBlock);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);


	// Wall square to latch onto the ship properly

	clearTimer(T4);
	while (time1(T4)<800){
		setMotorSpeed(left, min((time1(T4)*0.1), 30));
		setMotorSpeed(right, -1*min((time1(T4)*0.1), 30));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
}
