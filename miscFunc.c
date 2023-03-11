int min(int num1, int num2){
	if (num1<num2){
		return num1;
	}
	return num2;
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

task releaseBlock(){
		setMotorSpeed(arm, 15);
		sleep(700);
		setMotorSpeed(arm, -15);
		sleep(700);
		setMotorSpeed(arm, 0);
		stopTask(releaseBlock);
	}
