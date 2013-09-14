#include "console.h"
#include <iostream>

void Console::update(Model *model) {
	Move move = model->lastMove;
	std::cout << move.yaw << "," << move.pitch << "," << move.roll << std::endl;
}