#include <vector>
#include <iostream>

using namespace std;

struct Task{
	string className;
	bool startOnBoot;
};


class iOutputStrategyPattern{
public:
	virtual void output(vector<Task> list){
		for(Task i : list){
			cout << i.className << " " << i.startOnBoot << endl;
		}
	}
};
