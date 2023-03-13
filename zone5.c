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
	waitUntil(getMotorEncoder(right)>80);
	lfPID(0, -10, 30, 0.3, 0, 0, 1000, 3);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	sensorReset(GS1);
	sleep(1000);
	setMotorSpeed(right, 20);
	waitUntil(getGyroValue()<-90);
	setMotorSpeed(right, 0);
	setMotorSpeed(left, 20);
	setMotorSpeed(right, -20);
	waitUntil(getColorReflected(CS2)>50);
	waitUntil(getColorReflected(CS2)<30);
	lsPID(2, 35, 0.33, 0, 0, 3, 30, -0.33, 0, 0, 1200);
	movePID(40,-0.5,0,0,0.06,250,40,-0.5,0,0,0.06,250);
	clearTimer(T4);
	while (time1(T4)<2000){
		setMotorSpeed(left, min((time1(T4)*2), 40));
		setMotorSpeed(right, -1*min((time1(T4)*2), 40));
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	sensorReset(GS1);
	sleep(1000);
	setMotorSpeed(left, -30);
	waitUntil(getGyroValue()>95);
	waitUntil(getColourReflection(2)<20);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
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
