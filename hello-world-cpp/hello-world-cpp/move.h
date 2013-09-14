#ifndef MOVE_H_
#define MOVE_H_

class Move {
	double yaw, pitch, roll;
	double aX, aY, aZ;
	double wX, wY, wZ;

public:
	Move(double _yaw, double _pitch, double _roll, double _aX, double _aY, double _aZ,
		double _wX, double _wY, double _wZ) : yaw(_yaw), pitch(_pitch), roll(_roll),
		aX(_aX), aY(_aY), aZ(_aZ), wX(_wX), wY(_wY), wZ(_wZ) {}
};

#endif	// MOVE_H_