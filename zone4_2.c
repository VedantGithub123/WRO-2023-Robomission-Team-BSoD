void zone4(){ // This zone grabs the ships

	// Gets into position to grab the small ship
	movePID(50,-0.5,0,0,0.12,65,50,-0.5,0,0,0.12,-65);

	movePID(50,-0.5,0,0,0.12,0,80,-0.8,0,0,0.12,555);

	movePID(50,-0.5,0,0,0.12,540,50,-0.5,0,0,0.12,540);

	movePID(30,-0.5,0,0,0.06,-200,30,-0.5,0,0,0.06,200);


	// Grabs and brings the small ship to the line

	setMotorSpeed(grab, 100);

	sleep(500);

	setMotorSpeed(grab, 20);

	movePID(100,-0.6,0,0,0.16,715,100,-0.6,0,0,0.16,-715);

	setMotorSpeed(grab, -100);

	sleep(700);

	setMotorSpeed(grab, 0);
	resetMotorEncoder(grab);


	// Get into position to grab the big ship

	clearTimer(T4);
	while (time1(T4)<1200){
		setMotorSpeed(left, min((time1(T4)*2), 100));
		setMotorSpeed(right, -1*min((time1(T4)*2), 100));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	movePID(60,-0.5,0,0,0.16,-565,60,-0.5,0,0,0.16,565);

	movePID(60,-0.4,0,0,0.1,562,30,-0.9,0,0,0.06,0);

	movePID(40,-0.5,0,0,0.1,880,40,-0.5,0,0,0.1,-880);


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
