void zone1(){ // This zone completes the fueling, sensing the marking blocks, and goes to the cargo area
	startTask(sense);
	movePID(40,-1,0,0,0.12,-700,40,-1,0,0,0.12,700);
	movePID(70,-0.5,0,0,2,1080,70,-0.5,0,0,0.06,0);
	clearTimer(T4);
	while (time1(T4)<1400){
		setMotorSpeed(left, min((time1(T4)*2), 100));
		setMotorSpeed(right, -1*min((time1(T4)*2), 100));
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(20,-0.5,0,0,0.06,-170,20,-0.5,0,0,0.06,170);
	movePID(15,-0.5,0,0,0.015,0,30,-0.7,0,0,0.15,535);
	setMotorSpeed(left, -20);
	setMotorSpeed(right, 20);
	waitUntil(getColorReflected(CS2)>50);
	waitUntil(getColorReflected(CS2)<30);
	lsPID(2, 35, -0.25, 0, 0, 3, 30, 0.25, 0, 0, 800);
	movePID(50,-0.3,0,0,0.06,200,50,-0.3,0,0,0.06,-200);
}
