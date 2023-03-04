#include "iOutputStrategyPattern.h"

using namespace std;
/*
	static Task1 task1;
	static Task2 task2;

	RplTask* tasks[] = {&task1, &task2};
	const int taskCount = xyz;

	void setup(){
		task1->start();
		task2->start();
	}

	void loop(){
		task1->process();
		task2->process();
	}
*/

class ArduinoStrategyPattern : public iOutputStrategyPattern{
	void output(vector<string> list){
			
	}
};
