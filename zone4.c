void zone4(){ // This zone grabs up the ships
	movePID(20,-0.5,0,0,0.06,75,20,-0.5,0,0,0.06,-75);
	movePID(20,-0.5,0,0,0.06,0,70,-0.8,0,0,0.1,530);
	movePID(40,-0.5,0,0,0.1,540,40,-0.5,0,0,0.1,540);
	movePID(20,-0.5,0,0,0.06,-200,20,-0.5,0,0,0.06,200);
	setMotorSpeed(grab, 100);
	sleep(800);
	setMotorSpeed(grab, 20);
	movePID(40,-0.5,0,0,0.06,800,40,-0.5,0,0,0.06,-800);
	setMotorSpeed(grab, -100);
	waitUntil(getMotorEncoder(grab)<=0);
	setMotorSpeed(grab, 0);
	resetMotorEncoder(grab);
	movePID(60,-0.3,0,0,0.1,560,30,-0.9,0,0,0.06,0);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(20,-0.5,0,0,0.06,0,100,-0.8,0,0,0.1,-530);
	clearTimer(T4);
	while (time1(T4)<1000){
		setMotorSpeed(left, min((time1(T4)*0.1), 50));
		setMotorSpeed(right, -1*min((time1(T4)*0.1), 50));
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(40,-0.5,0,0,0.06,-215,40,-0.5,0,0,0.06,215);
	movePID(20,-0.5,0,0,0.06,0,40,-0.5,0,0,0.06,530);
	movePID(40,-0.5,0,0,0.06,600,40,-0.5,0,0,0.06,-600);
	setMotorSpeed(grab, 100);
	sleep(1000);
	setMotorSpeed(grab, 20);
	clearTimer(T4);
	while (time1(T4)<5000){
		setMotorSpeed(left, min((time1(T4)*0.1), 50));
		setMotorSpeed(right, -1*min((time1(T4)*0.1), 50));
	}
}
