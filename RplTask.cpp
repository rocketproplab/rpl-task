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
	if (status != STOPPED) {
		status = PAUSING;
	}
}

void RplTask::resume() {
	if (status == STOPPED) {
		status = RESUMING;
	}
}

void RplTask::process(float deltaTime) { //do stuff for task each loop
	if (status == STARTING) {
		onStart();
		status = RUNNING;
	}
	else if (status == RUNNING) {
		onLoop();
	}
	else if (status == PAUSING) {
		onPause();
		status = STOPPED;
	}
	else if (status == RESUMING) {
		onResume();
		status = RUNNING;
	}
}
