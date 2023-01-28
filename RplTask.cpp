#include "RplTask.h"

//RplTask::RplTask() {
//	status = CREATED;
//}
//
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
