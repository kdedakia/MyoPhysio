#include "model.h"
#include "state.h"

void Model::notifyObservers() {
	for (View &view : views)
		view.update(this);
}

void Model::move(Move &move) {
	lastMove = move;
	notifyObservers();
}

double distance(State state, double yaw, double pitch, double roll) {
	return sqrt(sq(yaw - state.yaw) + sq(pitch - state.pitch) + sq(roll - state.roll));
}

double sq(double x) {
	return x * x;
}

bool Model::isDetecting() {
	return detecting;
}

void Model::setDetecting(bool _detecting) {
	detecting = _detecting;
}

void Model::addObserver(View &view) {
	views.push_back(view);
}