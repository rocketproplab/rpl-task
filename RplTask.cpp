#include "RplTask.h"

RplTask::~RplTask() {
	//delete dependList;
}

TaskStatus RplTask::getStatus() {
	return status;
}

void RplTask::addDepend(RplTask* newDepend) { //add tasks this task is dependent on
	dependList.add(newDepend);
}

bool RplTask::checkDepend() { //true if dependencies are done otherwise false
	for (int i = 0; i < dependList.getSize(); i++) {
		if (dependList.get(i)->getStatus() != STOPPED) {
			return false;
		}
	}
	return true;
}

void RplTask::start() {
	if (checkDepend()) {
		status = STARTING;
	}
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
	//if (status == CREATED) {
	//	//do nothing
	//}
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
	//if (status == STOPPED) {
	//	//do nothing
	//}
}
