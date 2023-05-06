#include <vector>
#include <iostream>

using namespace std;

struct Task{
	string className;
	bool startOnBoot;
};


class IOutputStrategyPattern{
public:
	/**
	* Basic output strategy that just prints basic items of the task header
	*/
	virtual string output(vector<Task> list){
		string out = "";
		for(Task i : list){
			cout << i.className << " " << i.startOnBoot << endl;
			out += i.className + " " + to_string(i.startOnBoot) + "\n";
		}
		return out;
	}
};
