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

int htColor(int portNumber){
	readSensor(&HCS1);
	switch(portNumber){
	case 1:
		return HCS1.color;
	default:
		return 0;
	}
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

