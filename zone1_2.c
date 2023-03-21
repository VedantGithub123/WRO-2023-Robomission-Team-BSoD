void zone1(){ // This zone completes the fueling, sensing the marking blocks, and goes to the cargo area

	startTask(sense); // Starts the task to sense the blocks in parallel while moving

	movePID(40,-1,0,0,0.9,-700,40,-1,0,0,0.9,700); // Pushes the ship into the fueling area

	movePID(100,-0.5,0,0,2,1074,70,-0.5,0,0,0.06,0); // Turns to get into position


	// Wall squares
	clearTimer(T4);
	while (time1(T4)<1200){
		setMotorSpeed(left, min((time1(T4)*2), 100));
		setMotorSpeed(right, -1*min((time1(T4)*2), 100));
	}

	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	resetMotorEncoder(left);
	resetMotorEncoder(right);


	// Gets into position for line squaring
	movePID(50,-0.5,0,0,0.16,-153,50,-0.5,0,0,0.16,153);

	movePID(15,-0.5,0,0,0.015,0,50,-0.7,0,0,0.25,530);

	setMotorSpeed(left, -40);
	setMotorSpeed(right, 40);

	waitUntil(getColorReflected(CS2)>midpoint2+15);


	// Gets into position for sensing
	lsPID(2, midpoint2-3, -0.25, 0, 0, 3, midpoint3, 0.25, 0, 0, 1200);

	movePID(30,-0.5,0,0,0.06,230,30,-0.5,0,0,0.06,-230);
}
