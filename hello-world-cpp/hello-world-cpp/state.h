#include <string>

class State {

public:
	std::string exercise;
	std::string instruction;
	State *nextState;
	double yaw, pitch, roll;
	int duration;

};