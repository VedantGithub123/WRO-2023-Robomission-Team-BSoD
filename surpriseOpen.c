void surpriseInOpen(){ // This zone grabs the ships 0 = Left, 1 = Right

	// Gets into position to grab the small ship
	//movePID(50,-0.5,0,0,0.12,70,50,-0.5,0,0,0.12,-70);

	//movePID(50,-0.5,0,0,0.12,0,80,-0.8,0,0,0.12,575);

	//movePID(50,-0.5,0,0,0.12,543,50,-0.5,0,0,0.12,543);

	//movePID(30,-0.3,0,0,0.06,-230,30,-0.3,0,0,0.06,230);


	//// Grabs and brings the small ship to the line

	//setMotorSpeed(grab, 100);

	//sleep(500);

	//setMotorSpeed(grab, 20);

	//movePID(100,-0.6,0,0,0.16,705,100,-0.6,0,0,0.16,-705);

	//setMotorSpeed(grab, -100);

	//sleep(700);

	//setMotorSpeed(grab, 0);
	//resetMotorEncoder(grab);


	//// Get into position to grab the big ship

	clearTimer(T4);
	while (time1(T4)<1200){
		setMotorSpeed(left, min((time1(T4)*2), 100));
		setMotorSpeed(right, -1*min((time1(T4)*2), 100));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);



	//-------------------Surprise---------------------//

	// Gets into position for picking blocks
	movePID(15,-100.5,0,0,0.06,-187,15,-100.5,0,0,0.06,187;

	movePID(15,-0.5,0,0,0.015,0,15,-100.5,0,0,0.06,549);

	sleep(20);

	// Moves fast to get the the white cargo

	clearTimer(T4);
	while (getMotorEncoder(right)<350){ // Acceleration
		setMotorSpeed(left, -1*min((time1(T4)*0.1)+5, 30));
		setMotorSpeed(right, min((time1(T4)*0.1)+5, 30));
	}

	clearTimer(T4);
	while (!(getColorReflected(CS3)>midpoint2+15)){ // Decceleration
		setMotorSpeed(left, -30+min(time1(T4)*0.1, 15));
		setMotorSpeed(right, 30-min(time1(T4)*0.1, 15));
	}


	// Get into position for picking the block

	waitUntil(getColorReflected(CS3)>midpoint2+15);

	waitUntil(getColorReflected(CS2)<midpoint2-15);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);


	// Pick up the block

	movePID(20,-0.3,0,0,0.06,-170,20,-0.3,0,0,0.06,170);

	pickBlock();

	startTask(releaseBlock)

	movePID(30,-0.5,0,0,0.06,-520,30,-0.5,0,0,0.06,0);

	clearTimer(T4);
	while (time1(T4)<1200){
		setMotorSpeed(left, min((time1(T4)*2), 100));
		setMotorSpeed(right, -1*min((time1(T4)*2), 100));
	}

	lfPID(3, -90, midpoint3, -2.5, 0, -200, midpoint2+30, 3);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	movePID(20,-0.5,0,0,0.06,-110,20,-0.5,0,0,0.06,110);

	movePID(30,-0.5,0,0,0.06,0,30,-0.5,0,0,0.06,541);

	lfPID(0, -90, midpoint2, 2.5, 0, 200, 1000, 2);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);


	sleep(1000);

	movePID(60,-0.5,0,0,0.16,1370,60,-0.5,0,0,0.16,-1370);

	movePID(60,-0.5,0,0,0.16,0,60,-0.5,0,0,0.16,-470);

	clearTimer(T4);
	while (time1(T4)<2000){
		setMotorSpeed(left, min((time1(T4)*2), 100));
		setMotorSpeed(right, -1*min((time1(T4)*2), 100));
	}



	//BIG BOAT ERA fr fr
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(60,-0.5,0,0,0.16,-570,60,-0.5,0,0,0.16,570);

	movePID(60,-0.4,0,0,0.1,570,30,-0.9,0,0,0.06,0);

	movePID(40,-0.3,0,0,0.1,280,40,-0.3,0,0,0.1,-280);

	setMotorSpeed(left, 10);
	setMotorSpeed(right, -10);

	waitUntil(getColorReflected(CS2)>midpoint2+15);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	movePID(40,-0.3,0,0,0.1,800,40,-0.3,0,0,0.1,-800);



	//----------------End Of Surprise----------------//

	// Activate the mechanical AND gate

	setMotorSpeed(arm, 50);
	setMotorSpeed(grab, 50);
	sleep(300);

	setMotorSpeed(arm, -100);
	setMotorSpeed(grab, -100);
	sleep(300);

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
