int getColourReflection(int portNumber){ // Function to get color reflection by sensor
	switch(portNumber){
		case 2:
			return getColorReflected(CS2);
		case 3:
			return getColorReflected(CS3);
		default:
			return 0;
	}
}

int htColor(int portNumber){ // Function to get hitechnic color sensor color
	readSensor(&HCS1);
	switch(portNumber){
	case 1:
		return HCS1.color;
	default:
		return 0;
	}
}

// Function to get the color of a block
int getColorHTMarker(){ // 0 is no color, 1 is blue, 2 is green
	if (htColor(1)==2||htColor(1)==3){
		return 1;
		}else if (htColor(1)==4){
		return 2;
		}else{
		return 0;
	}
}

// Function to get the color of a block
int getColorHT(){ // 0 is no color, 1 is blue, 2 is green
	if (htColor(1)==2||htColor(1)==3){
		return 1;
		}else if (htColor(1)==4){
		return 2;
		}else{
		return 0;
	}
}