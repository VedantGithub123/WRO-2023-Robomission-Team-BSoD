void zone5(){ // This zone moves the ships and ends in the mooring area
	//setMotorSpeed(grab, 10);
	//movePID(50,-0.5,0,0,0.06,-540,70,-0.5,0,0,0.06,0);
	//setMotorSpeed(left, -20);
	//setMotorSpeed(right, 20);
	//waitUntil(getColorReflected(CS2)>50);

	//setMotorSpeed(left, 0);
	//setMotorSpeed(right, 0);
	//resetMotorEncoder(left);
	//resetMotorEncoder(right);
	//movePID(50,-0.5,0,0,2,0,50,-0.5,0,0,0.06,650);
	//sleep(500);
	//lfPID(1, -20, 30, 0.3, 0, 0, 3000, 3);
	//lfPID(3, -20, 30, 0.3, 0, 0, 30, 3);
	//lfPID(2, -20, 30, 0.3, 0, 0, 15, 3);
	//resetMotorEncoder(left);
	//resetMotorEncoder(right);
	//setMotorSpeed(left, -20);
	//setMotorSpeed(right, 20);
	//waitUntil(getMotorEncoder(right)>80);
	//lfPID(0, -10, 30, 0.3, 0, 0, 1000, 3);
	//setMotorSpeed(left, 0);
	//setMotorSpeed(right, 0);
	//resetMotorEncoder(left);
	//resetMotorEncoder(right);
	setMotorSpeed(grab, -1);
	movePID(50,-0.5,0,0,0.06,330,50,-0.5,0,0,0.06,0);
	//movePID(50,-0.5/4,0,0,0.06/4,145,50,-0.5,0,0,0.06,580);
}
