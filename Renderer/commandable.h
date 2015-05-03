#pragma once

enum COMMANDS
{
	JUMP,
	MOVE_FORWARD,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_BACKWARDS,
};

class Programmable {
public:
	Programmable(){};
	virtual ~Programmable(){};
	virtual void performAction(COMMANDS action);
};

