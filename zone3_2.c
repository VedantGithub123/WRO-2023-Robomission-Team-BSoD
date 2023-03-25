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

	movePID(70,-0.5,0,0,0.25,295,70,-0.5,0,0,0.25,295);

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

	waitUntil(getMotorEncoder(right)>40);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	dropBlock();

	//setMotorSpeed(grab, 20);
	//sleep(350);
	//setMotorSpeed(grab, 70);
	//sleep(800);
	//setMotorSpeed(grab, -10);
	//sleep(200);
	//setMotorSpeed(grab, 0);

	//movePID(20,-1,0,0,1,-30,20,-1,0,0,1,30);
	//sleep(200)
	//setMotorSpeed(grab, -100);
	//sleep(900);
	//setMotorSpeed(grab, 0);
	//resetMotorEncoder(grab);

	movePID(20,-0.5,0,0,0.06,-92,20,-0.5,0,0,0.06,92);

	dropBlock();
}
