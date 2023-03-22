void zone2(){ // This zone picks up the cargo, puts it in the ship, and goes back to the cargo area

	// Grabs blocks while moving forward
	clearTimer(T4);
	while (getMotorEncoder(right)<600){ // Stops at 600 degrees

		setMotorSpeed(left, -1*min((time1(T4)*0.1), 15));
		setMotorSpeed(right, min((time1(T4)*0.1), 15));

		if (getColorHT()==blocks[0]){ // Checks if the block is the same as the first position

			if (blocks[0]==1){
				sleep(30);
			}
  		writeDebugStream("%d", blocks[0]);

			blocks[0] = -1;

			setMotorSpeed(left, 0);
			setMotorSpeed(right, 0);

			pickBlock();

			sleep(2);

		}else if (getColorHT()==blocks[1]){ // Checks if the block is the same as the second position

			if (blocks[1]==1){
				sleep(30);
			}

  		writeDebugStream("%d", blocks[1]);
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

	waitUntil(htColor(1)>10);

	waitUntil(getColorReflected(CS2)<midpoint2-15);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	lsPID(2, midpoint2-3, -0.35, 0, 0, 3, midpoint3, 0.35, 0, 0, 1000);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);


	// Pick up the block

	pickBlock();


	startTask(releaseBlock); // Do task in parallel to make sure the block falls properly


	// Get to position for dropping blocks

	movePID(100,-1,0,0,0.15,-1070,50,-0.5,0,0,0.06,00);

	movePID(100,-1,0,0,0.15,-410,100,-1,0,0,0.15,410);

	setMotorSpeed(left, -20);
	setMotorSpeed(right, 20);

	waitUntil(getColorReflected(CS2)>midpoint2+15);

	waitUntil(getColorReflected(CS2)<midpoint2-25);

	lsPID(2, midpoint2-3, -0.35, 0, 0, 3, midpoint3+2, 0.35, 0, 0, 1200);

	movePID(50,-0.3,0,0,0.04,-705,50,-0.3,0,0,0.04,705);

	movePID(70,-0.3,0,0,0.06,0,60,-0.2,0,0,0.08,-1635);

	clearTimer(T4);
	while (time1(T4)<1500){
		setMotorSpeed(left, min((time1(T4)*0.3), 60));
		setMotorSpeed(right, -1*min((time1(T4)*0.3), 60));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);

	resetMotorEncoder(left);
	resetMotorEncoder(right);


	// Drop blocks onto the big ship

	movePID(20,-0.5,0,0,0.06,-145,20,-0.5,0,0,0.06,145);

	dropBlock();

	movePID(20,-0.5,0,0,0.06,-205,20,-0.5,0,0,0.06,205);

	dropBlock();

	movePID(20,-0.5,0,0,0.06,-88,20,-0.5,0,0,0.06,88);

	setMotorSpeed(grab, 20);
	sleep(350);
	setMotorSpeed(grab, 70);
	sleep(800);
	setMotorSpeed(grab, -20);
	sleep(300);
	setMotorSpeed(grab, 0);

	movePID(20,-1,0,0,1,30,20,-1,0,0,1,-30);

	setMotorSpeed(grab, -100);
	sleep(900);
	setMotorSpeed(grab, 0);
	resetMotorEncoder(grab);


	// Get into position for line squaring

	clearTimer(T4);
	while (time1(T4)<1200){
		setMotorSpeed(left, min((time1(T4)*0.2), 70));
		setMotorSpeed(right, -1*min((time1(T4)*0.3), 70));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	movePID(50,-0.5,0,0,0.16,-165,50,-0.5,0,0,0.16,165);

	movePID(15,-0.5,0,0,0.015,0,50,-0.7,0,0,0.25,543);

	setMotorSpeed(left, -40);
	setMotorSpeed(right, 40);

	waitUntil(getColorReflected(CS2)>midpoint2+15);


	// Gets into position for sensing
	lsPID(2, midpoint2-3, -0.25, 0, 0, 3, midpoint3, 0.25, 0, 0, 1200);

	movePID(40,-0.5,0,0,0.06,240,40,-0.5,0,0,0.06,-240);

	sleep(20);
}
