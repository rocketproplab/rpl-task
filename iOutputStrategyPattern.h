#include <vector>
#include <iostream>

using namespace std;


class iOutputStrategyPattern{
public:
	virtual void output(vector<string> list){
		for(string i : list){
			cout << i << endl;
		}
	}
};
