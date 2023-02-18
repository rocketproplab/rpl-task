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

	Graph graph;

	for(string path : taskPaths){
		string taskName = getTaskName(path);
		vector<string> dependencies = getDependencies(path);
		graph[taskName] = dependencies;
	}

	vector<string> sorted = topologicalSort(graph);

	outputWithOutputStrategy(sorted);	
	return 0;
}

vector<string> getDependencies(string path){
	//TODO	
}


vector<string> topologicalSort(Graph & g){
	//TODO	
}

void outputWithOutputStrategy(vector<string> & sorted){
	//TODO	
}
