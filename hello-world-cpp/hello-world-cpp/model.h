#ifndef MODEL_H_
#define MODEL_H_

#include <list>
#include <mutex>
#include <myo.h>
#include "move.h"
#include "view.h"

class Model {

	bool detecting;
	std::list<View&> views;
	Move lastMove;

	std::mutex moveLock;
	void notifyObservers();

public:
	Model() : detecting(false) {}
	void move(Move &move);
	bool isDetecting();
	void setDetecting(bool detecting);
	void addObserver(View &view);

};

#endif	// MODEL_H_