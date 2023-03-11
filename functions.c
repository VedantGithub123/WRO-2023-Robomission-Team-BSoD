int getColourReflection(int portNumber){
	switch(portNumber){
		case 2:
			return getColorReflected(CS2);
		case 3:
			return getColorReflected(CS3);
		default:
			return 0;
	}
}

int min(int num1, int num2){
	if (num1<num2){
		return num1;
	}
	return num2;
}

int htColor(int portNumber){
	readSensor(&HCS1);
	switch(portNumber){
	case 1:
		return HCS1.color;
	default:
		return 0;
	}
}
void movePID(float leftSpeed, float leftKP, float leftKI, float leftKD, float leftAcc, float leftDegrees, float rightSpeed, float rightKP, float rightKI, float rightKD, float rightAcc, float rightDegrees){
	clearTimer(T2);
	int lSpeed;
	int rSpeed;
	int oldTime = -1;
	int lOldDeg = 0;
	int lIntegral;
	int rOldDeg = 0;
	int rIntegral;
	while (time1(T2)<5000 && !(fabs(getMotorEncoder(left))<fabs(leftDegrees)+5&&fabs(getMotorEncoder(left))>fabs(leftDegrees)-5&&fabs(getMotorEncoder(right))<fabs(rightDegrees)+5&&fabs(getMotorEncoder(right))>fabs(rightDegrees)-5)){

		lSpeed = (getMotorEncoder(left)-leftDegrees)*leftKP+(getMotorEncoder(left)-lOldDeg)/(time1(T2)-oldTime)*leftKD;

		if (fabs(lSpeed)>leftSpeed){
			lSpeed = lSpeed/fabs(lSpeed)*leftSpeed;
		}
		if (fabs(lSpeed)>leftAcc*time1(T2)){
			lSpeed = lSpeed/fabs(lSpeed)*leftAcc*time1(T2);
		}

		rSpeed = (getMotorEncoder(right)-rightDegrees)*rightKP+(getMotorEncoder(right)-rOldDeg)/(time1(T2)-oldTime)*rightKD;

		if (fabs(rSpeed)>rightSpeed){
			rSpeed = rSpeed/fabs(rSpeed)*rightSpeed;
		}
		if (fabs(rSpeed)>rightAcc*time1(T2)){
			rSpeed = rSpeed/fabs(rSpeed)*rightAcc*time1(T2);
		}

		if (rightDegrees!=0&&rightSpeed!=0&&rSpeed!=0&&fabs(rSpeed)<5){
			rSpeed = rSpeed/fabs(rSpeed)*5;
		}
		if (leftDegrees!=0&&rightSpeed!=0&&lSpeed!=0&&fabs(lSpeed)<5){
			lSpeed = lSpeed/fabs(lSpeed)*5;
		}

		setMotorSpeed(left, lSpeed);
		setMotorSpeed(right, rSpeed);

		oldTime = time1(T2);
		lOldDeg = getMotorEncoder(left);
		rOldDeg = getMotorEncoder(right);
		sleep(10);
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
}
// States: 0: Degrees, 1: Seconds, 2: While Reflection > Target, 3: While Reflection < Target

void lfPID(int state, float speed, float midPoint, float kP, float kI, float kD, float target, int portNum){
	if (state == 1){
		clearTimer(T1);
		int oldTime = -1;
		int integral = 0;
		int oldRef = 0;
		int diff = 0;
		while (time1(T1)<target){
			diff = (getColourReflection(portNum)-midPoint)*kP+(getColourReflection(portNum)-oldRef)/(time1(T1)-oldTime)*kD;

			if (fabs(getColourReflection(portNum)-midPoint)<2){
				integral+=fabs(getColourReflection(portNum))*kI;
				if (integral>1){
					integral = 1;
				}
			}
			diff+=integral;
			setMotorSpeed(left, speed+diff);
			setMotorSpeed(right, -speed+diff);
			oldTime = time1(T1);
			oldRef = getColourReflection(portNum);
			sleep(20);
		}
		}else if (state == 2){
		clearTimer(T1);
		int oldTime = -1;
		int integral = 0;
		int oldRef = 0;
		int diff = 0;
		int tempPort = 5-portNum;
		while (getColourReflection(tempPort)>target){
			diff = (getColourReflection(portNum)-midPoint)*kP+(getColourReflection(portNum)-oldRef)/(time1(T1)-oldTime)*kD;

			if (fabs(getColourReflection(portNum)-midPoint)<2){
				integral+=fabs(getColourReflection(portNum))*kI;
				if (integral>1){
					integral = 1;
				}
			}
			diff+=integral;
			setMotorSpeed(left, speed+diff);
			setMotorSpeed(right, -speed+diff);
			oldTime = time1(T1);
			oldRef = getColourReflection(portNum);
			sleep(20);
		}
		}else if (state == 3){
		clearTimer(T1);
		int oldTime = -1;
		int integral = 0;
		int oldRef = 0;
		int diff = 0;
		int tempPort = 5-portNum;
		while (getColourReflection(tempPort)<target){
			diff = (getColourReflection(portNum)-midPoint)*kP+(getColourReflection(portNum)-oldRef)/(time1(T1)-oldTime)*kD;

			if (fabs(getColourReflection(portNum)-midPoint)<2){
				integral+=fabs(getColourReflection(portNum))*kI;
				if (integral>1){
					integral = 1;
				}
			}
			diff+=integral;
			setMotorSpeed(left, speed+diff);
			setMotorSpeed(right, -speed+diff);
			oldTime = time1(T1);
			oldRef = getColourReflection(portNum);
			sleep(20);
		}
		}else{
		clearTimer(T1);
		int oldTime = -1;
		int integral = 0;
		int oldRef = 0;
		int diff = 0;
		while (getMotorEncoder(right)<target){
			diff = (getColourReflection(portNum)-midPoint)*kP+(getColourReflection(portNum)-oldRef)/(time1(T1)-oldTime)*kD;

			if (fabs(getColourReflection(portNum)-midPoint)<5){
				integral+=fabs(getColourReflection(portNum))*kI;
				if (integral>1){
					integral = 1;
				}
			}
			diff+=integral;
			setMotorSpeed(left, speed+diff);
			setMotorSpeed(right, -speed+diff);
			oldTime = time1(T1);
			oldRef = getColourReflection(portNum);
			sleep(20);
		}
	}
	resetMotorEncoder(left);
	resetMotorEncoder(right);
}

void lsPID(int sensor1, float mid1, float kP1, float kI1, float kD1, int sensor2, float mid2, float kP2, float kI2, float kD2, float time){
	clearTimer(T3);

	int lSpeed;
	int rSpeed;
	int oldTime = -1;
	int lOldRef = 0;
	int lIntegral;
	int rOldRef = 0;
	int rIntegral;

	while (time1(T3)<time){
		lSpeed = (getColourReflection(sensor1)-mid1)*kP1+(getColourReflection(sensor1)-lOldRef)/(time1(T3)-oldTime)*kD1;
		rSpeed = (getColourReflection(sensor2)-mid2)*kP2+(getColourReflection(sensor2)-rOldRef)/(time1(T3)-oldTime)*kD2;

		setMotorSpeed(left, lSpeed);
		setMotorSpeed(right, rSpeed);
		oldTime = time1(T3);
		lOldRef = getColourReflection(sensor1);
		rOldRef = getColourReflection(sensor2);
		sleep(10);
	}
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);
}

int getColorHTMarker(){ // 0 is no color, 1 is blue, 2 is green
	if (htColor(1)==2||htColor(1)==3){
		return 1;
		}else if (htColor(1)==4){
		return 2;
		}else{
		return 0;
	}
}
int getColorHT(){
	if (htColor(1)==2||htColor(1)==3){
		return 1;
		}else if (htColor(1)==4){
		return 2;
		}else{
		return 0;
	}
}
void pickBlock(){
	setMotorSpeed(arm, 30);
	sleep(1100);
	setMotorSpeed(arm, -30);
	sleep(1200);
	setMotorSpeed(arm, 0);
}
void dropBlock(){
	setMotorSpeed(grab, 100);
	sleep(1100);
	setMotorSpeed(grab, -70);
	sleep(1000);
	setMotorSpeed(grab, 0);
	resetMotorEncoder(grab);
}
task sense(){
	int col = 0;
	while (true){
		col = getColorHTMarker();
		if (col>0){
			blocks[0] = col;
			break;
		}
	}

	waitUntil(htColor(1)==0);

	col = 0;

	while (true){
		col = getColorHTMarker();
		if (col>0){
			blocks[1] = col;
			break;
		}
	}
	switch(blocks[0]){
	case 1:
		playSound(soundException);
		break;
	case 2:
		playSound(soundBeepBeep);
		break;
	default:
		blocks[0] = 2;
		playSound(soundDownwardTones);
		break;
	}
	sleep(1000);
	switch(blocks[1]){
	case 1:
		playSound(soundException);
		break;
	case 2:
		playSound(soundBeepBeep);
		break;
	default:
		blocks[1] = 1;
		playSound(soundDownwardTones);
		break;
	}
	stopTask(sense);
}
task releaseBlock(){
		setMotorSpeed(arm, 15);
		sleep(700);
		setMotorSpeed(arm, -15);
		sleep(700);
		setMotorSpeed(arm, 0);
		stopTask(releaseBlock);
	}
