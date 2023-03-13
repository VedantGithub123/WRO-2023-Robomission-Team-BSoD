void zone3(){ // This zone pick up the remaining cargo and drops it in the small ship
	clearTimer(T4);
	while (getMotorEncoder(right)<850){
		setMotorSpeed(left, -1*min((time1(T4)*0.1), 20));
		setMotorSpeed(right, min((time1(T4)*0.1), 20));
		if (getColorHT()>0){
			setMotorSpeed(left, 0);
			setMotorSpeed(right, 0);
			pickBlock();
			clearTimer(T4);
			while (getColorHT()>0){
				setMotorSpeed(left, -1*min((time1(T4)*0.1), 20));
				setMotorSpeed(right, min((time1(T4)*0.1), 20));
			}
			sleep(2);
		}
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	startTask(releaseBlock);
	sleep(100);
	movePID(50,-0.5,0,0,0.15,280,50,-0.5,0,0,0.15,280);
	clearTimer(T4);
	while (time1(T4)<3000){
		setMotorSpeed(left, min((time1(T4)*1), 100));
		setMotorSpeed(right, -1*min((time1(T4)*1), 100));
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(20,-0.5,0,0,0.06,-470,20,-0.5,0,0,0.06,470);
	movePID(30,-0.5,0,0,0.03,-550,15,-0.15,0,0,0.015,0);
	movePID(30,-0.5,0,0,0.06,500,30,-0.5,0,0,0.06,-500);
	setMotorSpeed(left, 15);
	setMotorSpeed(right, -15);
	waitUntil(getColorReflected(CS2)>50);
	waitUntil(getColorReflected(CS2)<17);
	waitUntil(getColorReflected(CS2)>30);
	lsPID(2, 43, -0.3, 0, 0, 3, 35, 0.4, 0, 0, 1200);
	setMotorSpeed(left, -10);
	setMotorSpeed(right, 10);
	waitUntil(getColorReflected(CS2)<17);
	sleep(30);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	dropBlock();
	movePID(20,-0.5,0,0,0.06,-100,20,-0.5,0,0,0.06,100);
	dropBlock();
}
