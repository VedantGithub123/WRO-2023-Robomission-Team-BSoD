void zone5(){ // This zone moves the ships and ends in the mooring area
	movePID(50,-0.5,0,0,0.06,-180,70,-0.5,0,0,0.06,0);
	movePID(50,-0.5,0,0,0.06,0,50,-0.5,0,0,0.06,280);
	movePID(50,-0.5,0,0,0.06,-640,70,-0.5,0,0,0.06,0);
	setMotorSpeed(left, -20);
	setMotorSpeed(right, 20);
	waitUntil(getColorReflected(CS2)>midpoint2+15);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(40,-0.5,0,0,0.06,-470,40,-0.5,0,0,0.06,430);
	movePID(50,-0.5,0,0,0.06,450,50,-0.5,0,0,0.06,0);
	setMotorSpeed(left, 20);
	waitUntil(getColorReflected(CS2)>midpoint2+15);
	waitUntil(getColorReflected(CS2)<midpoint2-15);


	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	sleep(500);
	lfPID(1, -50, midpoint2, 0.4, 0, 0, 3000, 2);
	lfPID(3, -40, midpoint2, 0.3, 0, 0, midpoint3+5, 2);
	lfPID(2, -30, midpoint2, 0.2, 0, 0, midpoint3-20, 2);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	setMotorSpeed(left, -30);
	setMotorSpeed(right, 30);
	clearTimer(T4);
	waitUntil(time1(T4)>2200);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(30,-0.4,0,0,0.06,130,30,-0.4,0,0,0.06,-130);
	lsPID(2, midpoint2, 0.33, 0, 0, 3, midpoint3, -0.33, 0, 0, 1200);

	setMotorSpeed(right, 30);
	sleep(500);
	waitUntil(getColorReflected(CS3)<midpoint2-15);
	waitUntil(getColorReflected(CS3)>midpoint2+15);
	//waitUntil(getColorReflected(CS3)<midpoint2-15);
	resetMotorEncoder(right);
	waitUntil(getMotorEncoder(right)>100);


	setMotorSpeed(right, 0);
	sleep(1000);

	clearTimer(T4);
	while (time1(T4)<1500){
		setMotorSpeed(left, min((time1(T4)*2), 40));
		setMotorSpeed(right, -1*min((time1(T4)*2), 40));
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	sleep(500);
	clearTimer(T4);
	while (time1(T4)<1000){
		setMotorSpeed(left, -1*min((time1(T4)*2), 80));
		setMotorSpeed(right, min((time1(T4)*2), 80));
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	setMotorSpeed(grab, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);




}
