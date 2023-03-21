void zone4(){ // This zone grabs the ships

	// Gets into position to grab the small ship
	movePID(50,-0.5,0,0,0.16,65,50,-0.5,0,0,0.16,-65);

	movePID(50,-0.5,0,0,0.16,0,80,-0.8,0,0,0.16,555);

	movePID(50,-0.5,0,0,0.1,540,50,-0.5,0,0,0.16,540);

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

	movePID(60,-0.2,0,0,0.05,550,30,-0.9,0,0,0.06,0);

	movePID(30,-0.4,0,0,0.06,780,30,-0.4,0,0,0.06,-780);


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
		setMotorSpeed(left, min((time1(T4)*0.1), 20));
		setMotorSpeed(right, -1*min((time1(T4)*0.1), 20));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
}
