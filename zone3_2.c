void zone3(){ // This zone pick up the remaining cargo and drops it in the small ship

	// Grab blocks while moving
	clearTimer(T4);
	while (getMotorEncoder(right)<850){ // Stops at 850 degrees

		setMotorSpeed(left, -1*min((time1(T4)*0.1), 15));
		setMotorSpeed(right, min((time1(T4)*0.1), 15));

		if (getColorHT()>0){ // Checks if there is a block

			if (blocks[0]==1){
				sleep(60);
			}else{
				sleep(40);
			}

			setMotorSpeed(left, 0);
			setMotorSpeed(right, 0);

			pickBlock();

			clearTimer(T4);

			sleep(1);
		}
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);


	startTask(releaseBlock); // Makes sure the last block falls properly


	// Get into posiiton for dropping the blocks

	movePID(40,-0.5,0,0,0.25,298,40,-0.5,0,0,0.25,298);

	clearTimer(T4);

	while (time1(T4)<2100){
		setMotorSpeed(left, min((time1(T4)*2), 100));
		setMotorSpeed(right, -1*min((time1(T4)*2), 100));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	movePID(50,-0.5,0,0,0.09,-455,50,-0.5,0,0,0.09,455);

	movePID(40,-0.4,0,0,0.09,-554,15,-0.5,0,0,0.5,0);

	movePID(50,-0.5,0,0,0.09,520,50,-0.5,0,0,0.09,-520);

	setMotorSpeed(left, 20);
	setMotorSpeed(right, -20);

	waitUntil(getColorReflected(CS2)>midpoint2+15);

	setMotorSpeed(left, 10);
	setMotorSpeed(right, -10);

	waitUntil(getColorReflected(CS2)<midpoint2-25);

	//lsPID(2, midpoint2-3, -0.3, 0, 0, 3, midpoint3+3, 0.4, 0, 0, 1200);


	// Drops blocks onto the small ship

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	setMotorSpeed(left, -10);
	setMotorSpeed(right, 10);

	waitUntil(getMotorEncoder(right)>8);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	dropBlock();

	setMotorSpeed(grab, -10);

	movePID(20,-0.5,0,0,0.06,-90,20,-0.5,0,0,0.06,90);

	dropBlock();
}
