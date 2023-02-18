#include <iostream>
#include <vector>
#include "RplTask.h"
#include <string>
#include <unorder_map>
#include <tuple>

using namespace std;

//Current syntax for header comment:
/*
CLASS: Task3
RPL-TASK-DEPENDENCIES
{
	Task1
	Task2
}
END-TASK-DEPENDENCIES
*/



int main(int argc, char** argv){
	if(argc == 0){
		return 1;
	}

	vector<string> taskPaths;
	for(int i = 0; i < argc; ++i){
		taskPaths.push_back(argv[i]);
	}

	for(string path : taskPaths){
		vector<string> dependencies = getDependencies(path);
		//TODO Make graph data structure:

	}

	vector<string> sorted = topologicalSort();//TODO

	outputWithOutputStrategy(sorted);	
	return 0;
}

vector<string> getDependencies(string path){
	//TODO	
}


vector<string> topologicalSort(){
	//TODO	
}

void outputWithOutputStrategy(vector<string> & sorted){
	//TODO	
}
