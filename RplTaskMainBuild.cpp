#include "PrecompilationCode/PrecompTopSort.h"

using namespace std;

int main(int argc, char** argv){
	if(argc <= 1){
		cout << "Wrong number of inputs" << endl;
		return 1;
	}
	
	//Get all task files to sort
	vector<string> taskPaths;
	for(int i = 1; i < argc; ++i){
		taskPaths.push_back(argv[i]);
	}

	Graph graph;
	unordered_map<string, Task> taskMap;

	//Construct graph
	for(string path : taskPaths){
		string contents=getFileContents(path);
		string taskName = getTaskName(contents);
		bool isStart = isTaskStartOnBoot(contents);
		vector<string> dependencies = getDependencies(contents);

		Task task;
		task.className = taskName;
		task.startOnBoot = isStart;

		graph[taskName] = dependencies;
		taskMap[taskName] = task;
	}
	
	//Sort Tasks
	vector<string> sorted  = topologicalSort(graph);
	vector<Task> sortedTasks;

	for(string str : sorted){
		sortedTasks.push_back(taskMap[str]);
	}
	
	//Use output strategy to create code
	ArduinoStrategyPattern pattern;
	outputWithOutputStrategy(sortedTasks, &pattern);	
	return 0;
}
