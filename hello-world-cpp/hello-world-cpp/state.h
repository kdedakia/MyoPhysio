#ifndef STATE_H_
#define STATE_H_

#include <string>

class State {

public:
	std::string exercise;
	std::string instruction;
	State *nextState;
	double yaw, pitch, roll;
	int duration;

};

#endif	// STATE_H_