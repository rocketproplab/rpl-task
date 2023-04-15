#include "RplTask.h"

RplTask::~RplTask() {
}

TaskStatus RplTask::getStatus() {
	return status;
}

void RplTask::start() {
	status = STARTING;
	//else { 
	//TODO Whoopsy, error display?
	//}
}

void RplTask::pause() {
	status = PAUSING;
}

void RplTask::resume() {
	if (status == PAUSED) {
		status = RESUMING;
	}
}

void RplTask::process(float deltaTime) { //do stuff for task each loop
	//if (status == CREATED) {
	//	//do nothing
	//}
	if (status == STARTING) {
		onStart();
		status = RUNNING;
	}
	if (status == RUNNING) {
		onLoop();
	}
	if (status == PAUSING) {
		onPause();
		status = PAUSED;
	}
	//if (status == PAUSED) {
	//	//do nothing
	//}
	if (status == RESUMING) {
		onResume();
		status = RUNNING;
	}
	//if (status == STOPPED) {
	//	//do nothing
	//}
}
