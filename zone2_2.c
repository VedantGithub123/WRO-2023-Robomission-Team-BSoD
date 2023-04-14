void zone2(){ // This zone picks up the cargo, puts it in the ship, and goes back to the cargo area

	setMotorSpeed(arm, -5);

	// Grabs blocks while moving forward
	clearTimer(T4);
	while (getMotorEncoder(right)<600){ // Stops at 600 degrees

		setMotorSpeed(left, -1*min((time1(T4)*0.1), 15));
		setMotorSpeed(right, min((time1(T4)*0.1), 15));

		if (getColorHT()==blocks[0]){ // Checks if the block is the same as the first position

			if (blocks[0]==1){
				sleep(60);
			}else{
				sleep(40);
			}

			blocks[0] = -1;

			setMotorSpeed(left, 0);
			setMotorSpeed(right, 0);

			pickBlock();

			sleep(2);

		}else if (getColorHT()==blocks[1]){ // Checks if the block is the same as the second position

			if (blocks[1]==1){
				sleep(60);
			}else{
				sleep(40);
			}

			blocks[1] = -1;

			setMotorSpeed(left, 0);
			setMotorSpeed(right, 0);

			pickBlock();

			sleep(1);

		}
	}


	// Moves fast to get the the white cargo

	clearTimer(T4);
	while (getMotorEncoder(right)<850){ // Acceleration
		setMotorSpeed(left, -1*min((time1(T4)*0.5)+5, 70));
		setMotorSpeed(right, min((time1(T4)*0.5)+5, 70));
	}

	clearTimer(T4);
	while (getMotorEncoder(right)<1100){ // Decceleration
		setMotorSpeed(left, -70+min(time1(T4)*0.3, 55));
		setMotorSpeed(right, 70-min(time1(T4)*0.3, 55));
	}


	// Get into position for picking the block

	waitUntil(getColorReflected(CS3)>midpoint2+15);

	waitUntil(getColorReflected(CS2)<midpoint2-15);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	lsPID(2, midpoint2-3, -0.3, 0, 0, 3, midpoint3, 0.3, 0, 0, 1000);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);


	// Pick up the block

	pickBlock();


	// Get to position for dropping blocks

	startTask(releaseBlock); // Do task in parallel to make sure the block falls properly

	movePID(100,-0.3,0,0,0.06,1250,100,-0.3,0,0,0.06,-1250);

	movePID(70,-0.3,0,0,0.06,0,60,-0.5,0,0,0.08,-524);

	setMotorSpeed(grab, -10);

	clearTimer(T4);
	while (time1(T4)<700){
		setMotorSpeed(left, min((time1(T4)*0.3), 60));
		setMotorSpeed(right, -1*min((time1(T4)*0.3), 60));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);

	resetMotorEncoder(left);
	resetMotorEncoder(right);


	// Drop blocks onto the big ship

	movePID(20,-0.5,0,0,0.06,-137,20,-0.5,0,0,0.06,137);

	dropBlock();

	setMotorSpeed(grab, -10);

	movePID(20,-0.5,0,0,0.06,-205,20,-0.5,0,0,0.06,205);

	dropBlock();

	setMotorSpeed(grab, -10);

	movePID(20,-0.5,0,0,0.06,-86,20,-0.5,0,0,0.06,86);

	setMotorSpeed(grab, 20);
	sleep(350);
	setMotorSpeed(grab, 70);
	sleep(800);
	setMotorSpeed(grab, -10);
	sleep(170);
	setMotorSpeed(grab, 0);

	movePID(20,-1,0,0,1,60,20,-1,0,0,1,-60);
	sleep(200);
	setMotorSpeed(grab, -100);
	sleep(600);
	setMotorSpeed(grab, 0);
	resetMotorEncoder(grab);


	// Get into position for picking blocks

	clearTimer(T4);
	while (time1(T4)<1400){
		setMotorSpeed(left, min((time1(T4)*0.2), 70));
		setMotorSpeed(right, -1*min((time1(T4)*0.3), 70));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	sleep(200);

	movePID(30,-0.5,0,0,0.1,-178,30,-0.5,0,0,0.1,178);

	movePID(15,-0.5,0,0,0.01,0,30,-0.5,0,0,0.1,548);

	sleep(20);
}
