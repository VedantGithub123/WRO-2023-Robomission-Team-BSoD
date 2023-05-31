void twoRed(int num){ // This zone grabs the ships 0 = Left, 1 = Right

	// Gets into position to grab the small ship
	movePID(50,-0.5,0,0,0.12,70,50,-0.5,0,0,0.12,-70);

	movePID(50,-0.5,0,0,0.12,0,80,-0.8,0,0,0.12,575);

	movePID(50,-0.5,0,0,0.12,543,50,-0.5,0,0,0.12,543);

	movePID(30,-0.3,0,0,0.06,-230,30,-0.3,0,0,0.06,230);


	// Grabs and brings the small ship to the line

	setMotorSpeed(grab, 100);

	sleep(500);

	setMotorSpeed(grab, 20);

	movePID(100,-0.6,0,0,0.16,705,100,-0.6,0,0,0.16,-705);

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



	//-------------------Surprise---------------------//

	movePID(60,-0.5,0,0,0.06,-370,60,-0.5,0,0,0.06,370);

	movePID(60,-0.4,0,0,0.1,0,30,-0.5,0,0,0.06,541);

	clearTimer(T4);
	while (getMotorEncoder(right)<150){ // Acceleration
		setMotorSpeed(left, -1*min((time1(T4)*0.1)+5, 60));
		setMotorSpeed(right, min((time1(T4)*0.1)+5, 60));
	}

	clearTimer(T4);
	while (!(getColorReflected(CS3)>midpoint2+15)){ // Decceleration
		setMotorSpeed(left, -60+min(time1(T4)*0.1, 25));
		setMotorSpeed(right, 60-min(time1(T4)*0.1, 25));
	}

	waitUntil(getColorReflected(CS3)>midpoint2+15);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	if (num){

		movePID(60,-0.5,0,0,0.06,-170,60,-0.5,0,0,0.06,170);

		movePID(60,-0.4,0,0,0.1,570,30,-0.9,0,0,0.06,0);

		setMotorSpeed(grab, 100);

		sleep(600);

		setMotorSpeed(grab, 0);

		clearTimer(T4);
		while (time1(T4)<1500){
			setMotorSpeed(left, -1*min((time1(T4)*0.1)+5, 30));
			setMotorSpeed(right, min((time1(T4)*0.1)+5, 30));
		}

		setMotorSpeed(left, 0);
		setMotorSpeed(right, 0);
		resetMotorEncoder(left);
		resetMotorEncoder(right);

	}else{
		movePID(60,-0.5,0,0,0.06,-320,60,-0.5,0,0,0.06,320);

		movePID(60,-0.4,0,0,0.1,568,30,-0.9,0,0,0.06,0);

		setMotorSpeed(right, -10);

		waitUntil(getColorReflected(CS3)>midpoint2+15);

		setMotorSpeed(right, 0);

		resetMotorEncoder(right);


		setMotorSpeed(grab, 100);

		sleep(600);

		setMotorSpeed(grab, 0);

		lfPID(1, -30, midpoint3, 0.5, 0, 40, 1500, 3);

		setMotorSpeed(left, 0);
		setMotorSpeed(right, 0);
		resetMotorEncoder(left);
		resetMotorEncoder(right);
	}

	movePID(20,-0.5,0,0,0.16,30,20,-0.5,0,0,0.16,-30);

	setMotorSpeed(grab, -100);

	sleep(1200);

	setMotorSpeed(grab, -5);

	movePID(40,-0.5,0,0,0.16,275,40,-0.5,0,0,0.16,275);

	setMotorSpeed(left, 10);
	setMotorSpeed(right, -10);

	waitUntil(getColorReflected(CS3)>midpoint3+15);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);


	movePID(20,-0.5,0,0,0.16,-90,20,-0.5,0,0,0.16,90);

	movePID(40,-0.5,0,0,0.16,278,40,-0.5,0,0,0.16,278);

	clearTimer(T4);
	while (time1(T4)<1200){
		setMotorSpeed(left, min((time1(T4)*2), 100));
		setMotorSpeed(right, -1*min((time1(T4)*2), 100));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);


	lfPID(0, -90, midpoint3, -2.5, 0, -200, 1200, 3);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	movePID(40,-0.5,0,0,0.16,0,30,-0.5,0,0,0.06,-293);

	movePID(30,-0.5,0,0,0.16,320,30,-0.5,0,0,0.06,0);

	setMotorSpeed(grab, 10);

	sleep(520);

	setMotorSpeed(grab, 0);

	movePID(20,-0.5,0,0,0.06,-300,20,-0.5,0,0,0.06,300);

	setMotorSpeed(grab, 100);

	sleep(600);

	setMotorSpeed(grab, 0);

	movePID(20,-0.5,0,0,0.06,350,20,-0.5,0,0,0.06,-350);

	setMotorSpeed(grab, -100);

	sleep(600);

	setMotorSpeed(grab, 0);

	//AFTER DROPPING RED
	movePID(30,-0.5,0,0,0.16,235,30,-0.5,0,0,0.06,0);
	movePID(40,-0.5,0,0,0.16,0,30,-0.5,0,0,0.06,-235);

	//movePID(30,-0.5,0,0,0.06,-800,30,-0.5,0,0,0.06,800);
	clearTimer(T4);
	while (time1(T4)<1000){
		setMotorSpeed(left, -1*min((time1(T4)*2), 50));
		setMotorSpeed(right, min((time1(T4)*2), 50));
	}

	//wall sqr
	clearTimer(T4);
	while (time1(T4)<2200){
		setMotorSpeed(left, min((time1(T4)*2), 100));
		setMotorSpeed(right, -1*min((time1(T4)*0.075), 100));
	}

	//SMALL BOAT ERA fr fr
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
