int min(int num1, int num2){ // Finds minimum value of 2 integers
	if (num1<num2){
		return num1;
	}
	return num2;
}

void pickBlock(){ // Picks up a block
	setMotorSpeed(arm, 40);
	sleep(1000);
	setMotorSpeed(arm, -100);
	sleep(600);
	setMotorSpeed(arm, 0);
}

void dropBlock(){ // Drops a block
	setMotorSpeed(grab, 20);
	sleep(350);
	setMotorSpeed(grab, 60);
	sleep(900);
	setMotorSpeed(grab, -90);
	sleep(700);
	setMotorSpeed(grab, 0);
	resetMotorEncoder(grab);
}

task sense(){ // Sensing task
	int col = 0;
	while (true){
		col = getColorHTMarker();
		if (col>0){
			blocks[0] = col;
			break;
		}
	}

	waitUntil(htColor(1)==0);
	sleep(10);
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

task releaseBlock(){ // Task to fully release the last block
		setMotorSpeed(arm, 15);
		sleep(700);
		setMotorSpeed(arm, -15);
		sleep(700);
		setMotorSpeed(arm, 0);
		stopTask(releaseBlock);
}
