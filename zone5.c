void zone5(){ // This zone moves the ships and ends in the mooring area
	setMotorSpeed(grab, 10);
	movePID(50,-0.5,0,0,0.06,-180,70,-0.5,0,0,0.06,0);
	movePID(50,-0.5,0,0,0.06,0,50,-0.5,0,0,0.06,280);
	movePID(50,-0.5,0,0,0.06,-640,70,-0.5,0,0,0.06,0);
	setMotorSpeed(left, -20);
	setMotorSpeed(right, 20);
	waitUntil(getColorReflected(CS2)>50);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(40,-0.5,0,0,0.06,-330,40,-0.5,0,0,0.06,330);
	movePID(50,-0.5,0,0,0.06,450,50,-0.5,0,0,0.06,0);
	setMotorSpeed(left, 20);
	waitUntil(getColorReflected(CS3)>50);
	waitUntil(getColorReflected(CS3)<20);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	sleep(500);
	lfPID(1, -20, 30, 0.3, 0, 0, 3000, 3);
	lfPID(3, -20, 30, 0.3, 0, 0, 30, 3);
	lfPID(2, -20, 30, 0.3, 0, 0, 15, 3);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	setMotorSpeed(left, -20);
	setMotorSpeed(right, 20);
	waitUntil(getMotorEncoder(right)>85);
	lfPID(0, -10, 30, 0.3, 0, 0, 1000, 3);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	setMotorSpeed(right, 20);
	waitUntil(htColor(1)>5);
	resetMotorEncoder(right);
	setMotorSpeed(right, 10);
	waitUntil(getMotorEncoder(right)>148);
	setMotorSpeed(right, 0);
	setMotorSpeed(left, 20);
	setMotorSpeed(right, -20);
	waitUntil(getColorReflected(CS2)>50);
	waitUntil(getColorReflected(CS2)<30);
	lsPID(2, 35, 0.33, 0, 0, 3, 30, -0.33, 0, 0, 1200);
	movePID(30,-0.4,0,0,0.06,230,30,-0.4,0,0,0.06,230);


	setMotorSpeed(left, 20);
	setMotorSpeed(right, -20);

	waitUntil(getMotorEncoder(left)>530);

	waitUntil(getColorReflected(CS3)>50);
	waitUntil(getColorReflected(CS3)<30);
	lsPID(2, 35, 0.43, 0, 0, 3, 30, -0.43, 0, 0, 1200);

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(50,-0.5,0,0,0.06,-590,50,-0.5,0,0,0.06,0);
	//sleep(1000);
	//setMotorSpeed(left, -15);
	////waitUntil(getColourReflection(2)>50);
	//waitUntil(getColourReflection(2)<20);
	//waitUntil(getColourReflection(3)<20);
	//resetMotorEncoder(left);
	//waitUntil(getMotorEncoder(left)<-30);
	//setMotorSpeed(left, 0);
	//setMotorSpeed(right, 0);
	//resetMotorEncoder(left);
	//resetMotorEncoder(right);
	clearTimer(T4);
	while (time1(T4)<1000){
		setMotorSpeed(left, min((time1(T4)*2), 40));
		setMotorSpeed(right, -1*min((time1(T4)*2), 40));
	}
	clearTimer(T4);
	while (time1(T4)<3000){
		setMotorSpeed(left, -1*min((time1(T4)*2), 40));
		setMotorSpeed(right, min((time1(T4)*2), 40));
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	setMotorSpeed(grab, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
}
