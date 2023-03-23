void zone3(){ // This zone pick up the remaining cargo and drops it in the small ship

	// Grab blocks while moving
	clearTimer(T4);
	while (getMotorEncoder(right)<850){ // Stops at 850 degrees

		setMotorSpeed(left, -1*min((time1(T4)*0.1), 20));
		setMotorSpeed(right, min((time1(T4)*0.1), 20));

		if (getColorHT()>0){ // Checks if there is a block

			if (blocks[0]==1){
				sleep(30);
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

	movePID(70,-0.5,0,0,0.25,289,70,-0.5,0,0,0.25,289);

	clearTimer(T4);

	while (time1(T4)<2100){
		setMotorSpeed(left, min((time1(T4)*2), 100));
		setMotorSpeed(right, -1*min((time1(T4)*2), 100));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	movePID(50,-0.5,0,0,0.16,-460,50,-0.5,0,0,0.16,460);

	movePID(60,-0.5,0,0,0.16,-550,15,-0.5,0,0,0.5,0);

	movePID(50,-0.5,0,0,0.16,520,50,-0.5,0,0,0.16,-520);

	setMotorSpeed(left, 40);
	setMotorSpeed(right, -40);

	waitUntil(getColorReflected(CS2)>midpoint2+15);

	waitUntil(getColorReflected(CS2)<midpoint2-25);

	//waitUntil(getColorReflected(CS2)>midpoint2-15);

	lsPID(2, midpoint2-3, -0.3, 0, 0, 3, midpoint3+3, 0.4, 0, 0, 1200);


	// Drops blocks onto the small ship

	setMotorSpeed(left, -10);
	setMotorSpeed(right, 10);

	waitUntil(getMotorEncoder(right)>35);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	dropBlock();

	movePID(20,-0.5,0,0,0.06,-94,20,-0.5,0,0,0.06,94);

	dropBlock();
}
