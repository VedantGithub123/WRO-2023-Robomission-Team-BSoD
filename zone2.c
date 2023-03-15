void zone2(){ // This zone picks up the cargo, puts it in the ship, and goes back to the cargo area
	clearTimer(T4);
	while (getMotorEncoder(right)<600){
		setMotorSpeed(left, -1*min((time1(T4)*0.1), 15));
		setMotorSpeed(right, min((time1(T4)*0.1), 15));
		if (getColorHT()==blocks[0]){
			if (blocks[0]==1){
				sleep(10);
			}
			blocks[0] = -1;
			setMotorSpeed(left, 0);
			setMotorSpeed(right, 0);
			pickBlock();
			clearTimer(T4);
			while (getColorHT()>0){
				setMotorSpeed(left, -1*min((time1(T4)*0.1), 15));
				setMotorSpeed(right, min((time1(T4)*0.1), 15));
			}
			sleep(2);
		}else if (getColorHT()==blocks[1]){
			if (blocks[0]==1){
				sleep(10);
			}
			blocks[1] = -1;
			setMotorSpeed(left, 0);
			setMotorSpeed(right, 0);
			pickBlock();
			clearTimer(T4);
			while (getColorHT()>0){
				setMotorSpeed(left, -1*min((time1(T4)*0.1), 15));
				setMotorSpeed(right, min((time1(T4)*0.1), 15));
			}
			sleep(1);
		}
	}
	clearTimer(T4);
	while (getMotorEncoder(right)<850){
		setMotorSpeed(left, -1*min((time1(T4)*0.5)+5, 70));
		setMotorSpeed(right, min((time1(T4)*0.5)+5, 70));
	}
	clearTimer(T4);
	while (getMotorEncoder(right)<1100){
		setMotorSpeed(left, -70+min(time1(T4)*0.3, 55));
		setMotorSpeed(right, 70-min(time1(T4)*0.3, 55));
	}

	waitUntil(htColor(1)>10);
	waitUntil(getColorReflected(CS2)<midpoint2-15);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	lsPID(2, midpoint2, -0.35, 0, 0, 3, midpoint3, 0.35, 0, 0, 1000);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	pickBlock();
	startTask(releaseBlock);
	movePID(100,-1,0,0,0.15,-1070,50,-0.5,0,0,0.06,00);
	movePID(100,-1,0,0,0.15,-450,100,-1,0,0,0.15,450);
	setMotorSpeed(left, -20);
	setMotorSpeed(right, 20);
	waitUntil(getColorReflected(CS2)>midpoint2+15);
	waitUntil(getColorReflected(CS2)<midpoint2-25);
	lsPID(2, midpoint2, -0.35, 0, 0, 3, midpoint3, 0.35, 0, 0, 1200);
	movePID(30,-0.3,0,0,0.04,-690,30,-0.3,0,0,0.04,690);
	movePID(70,-0.3,0,0,0.06,0,30,-0.4,0,0,0.04,-1635);
	clearTimer(T4);
	while (time1(T4)<2000){
		setMotorSpeed(left, min((time1(T4)*0.3), 60));
		setMotorSpeed(right, -1*min((time1(T4)*0.3), 60));
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(20,-0.5,0,0,0.06,-145,20,-0.5,0,0,0.06,145);
	dropBlock();
	movePID(20,-0.5,0,0,0.06,-202,20,-0.5,0,0,0.06,202);
	dropBlock();
	movePID(20,-0.5,0,0,0.06,-85,20,-0.5,0,0,0.06,85);
	dropBlock();

	clearTimer(T4);
	while (time1(T4)<1000){
		setMotorSpeed(left, min((time1(T4)*0.2), 70));
		setMotorSpeed(right, -1*min((time1(T4)*0.3), 70));
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
	movePID(20,-0.5,0,0,0.06,-170,20,-0.5,0,0,0.06,170);
	movePID(15,-0.5,0,0,0.015,0,30,-0.7,0,0,0.15,527);
	setMotorSpeed(left, -20);
	setMotorSpeed(right, 20);
	waitUntil(getColorReflected(CS2)>50);
	waitUntil(getColorReflected(CS2)<30);
	lsPID(2, midpoint2+2, -0.25, 0, 0, 3, midpoint3, 0.25, 0, 0, 1200);
	movePID(30,-0.3,0,0,0.06,200,30,-0.3,0,0,0.06,-200);
}
