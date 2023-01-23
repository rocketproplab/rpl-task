#include "RplTask.h"
#include "TaskLinkedList.h"
class RplTask {
private:
	TaskLinkedList dependList;
	TaskStatus status; //CREATED, STARTING, RUNNING, PAUSING, PAUSED, RESUMING, STOPPED 
protected:
	virtual void onStart(); // Children implement for first-time start behavior.
	virtual void onResume(); // Children implement for handling resume
	virtual void onPause(); // Children implement for handling pause
	virtual void onLoop(); // Children implement for handling loop
public:
	RplTask() {
		status = CREATED;
	}

	~RplTask() {
		dependList.~TaskLinkedList();
	}

	TaskStatus getStatus() {
		return status;
	}

	void addDepend(*RplTask newDepend) { //add tasks this task is dependent on
		dependList.add(newDepend);
	}

	bool checkDepend() { //true if dependencies are done otherwise false
		for (int i = 0; i < dependList.getSize(); i++) {
			if (dependList.get(i).getStatus() != STOPPED) {
				return false;
			}
		}
		return true;
	}

	void start() {
		if (checkDependencies()) {
			status = STARTING;
		}
		//else { 
		//TODO Whoopsy, error display?
		//}
	}

	void pause() {
		status = PAUSING;
	}

	void resume() {
		if (status == PAUSED) {
			status = RESUMING;
		}
	}

	void process() { //do stuff for task each loop
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
};