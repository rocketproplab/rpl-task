#include <tuple>
#include <regex>
#include <fstream>
#include <iostream>
#include <vector>
#include "RplTask.h"
#include <string>
#include <unordered_map>
#include <tuple>
#include "PrecompTopSort.h"
#include <unordered_set>

using namespace std;

//Current syntax for header comment:
/*
RPL-TASK-HEADER
CLASS: Task3
START-ON-BOOT: TRUE/FALSE
TASK-DEPENDENCIES
Task1
Task2
END-TASK-DEPENDENCIES
END-RPL-TASK-HEADER
*/



int main(int argc, char** argv){
	if(argc == 0){
		return 1;
	}

	vector<string> taskPaths;
	for(int i = 1; i < argc; ++i){
		taskPaths.push_back(argv[i]);
	}

	Graph graph;
	unordered_map<string, Task> taskMap;

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

	vector<string> sorted  = topologicalSort(graph);
	vector<Task> sortedTasks;

	for(string str : sorted){
		sortedTasks.push_back(taskMap[str]);
	}

	iOutputStrategyPattern pattern;
	outputWithOutputStrategy(sortedTasks, pattern);	
	return 0;
}



string getFileContents(string path){
	string output;
	bool flag = true;
	ifstream file(path);
	if(file.is_open()){
		string line;
		while(file){
			getline(file, line);
			if(!flag){
				output += "\n";
			}
			flag = false;
			output +=  line;		
		}
	}
	return output;
}

vector<string> getDependencies(string fileContents){	
	vector<string> dependencies;

	string rplString= "TASK-DEPENDENCIES" ;
	int rplSize = rplString.size() + 1; 
	int startIndex = fileContents.find(rplString) + rplSize;

	string newString = fileContents.substr(startIndex) ;
	string line = newString.substr(0,newString.find('\n')) ;

	while (line != "END-TASK-DEPENDENCIES") {
		dependencies.push_back(line) ;
		newString = newString.substr(newString.find('\n') + 1) ;
		line = newString.substr(0,newString.find('\n')) ;
	}

	return dependencies;
}

string getTaskName(string contents){
	regex expression("RPL-TASK-HEADER(.|\n)*?END-RPL-TASK-HEADER");
	smatch match;
	regex_search(contents, match, expression);
	string header = match[0];
	regex classExpression("CLASS:.*");
	smatch classMatch;
	regex_search(header, classMatch, classExpression);
	string taskName = classMatch[0];
	taskName = taskName.substr(taskName.find(" ")+1);	
	return taskName;
}

bool isTaskStartOnBoot(string contents){
	regex expression("RPL-TASK-HEADER(.|\n)*?END-RPL-TASK-HEADER");
	smatch match;
	regex_search(contents, match, expression);
	string header = match[0];
	regex startExpression("START-ON-BOOT:.*");
	smatch startMatch;
	regex_search(header, startMatch, startExpression);
	string startStatus = startMatch[0];
	startStatus = startStatus.substr(startStatus.find(" ")+1);	
	if(startStatus == "TRUE"){
		return true;
	}else{
		return false;
	}
}

vector<string> topologicalSort(Graph & g){
	vector<string> topologicalOrdering;
	unordered_set<string> permanentMarks; 
	unordered_set<string> temporaryMarks; 
	

	for (auto element: g) {
		visit(element.first,temporaryMarks,permanentMarks,topologicalOrdering,g);
	}

		

	return topologicalOrdering; 
}

void visit(string task, unordered_set<string> & temporaryMarks, unordered_set<string> & permanentMarks, vector<string> & topologicalOrder, Graph & g ) {

	if (permanentMarks.find(task) != permanentMarks.end() ) {
		return; 
	}

	else if (temporaryMarks.find(task) != temporaryMarks.end()) {
		throw std::invalid_argument("Graph has cycle");
	}

	temporaryMarks.insert(task);

	for (auto adjacentNodes : g[task]) {
		visit(adjacentNodes, temporaryMarks, permanentMarks, topologicalOrder, g);
	}

	temporaryMarks.erase(task);
	permanentMarks.insert(task);

	topologicalOrder.push_back(task);
}

void outputWithOutputStrategy(vector<Task> & sorted, iOutputStrategyPattern pattern){
	pattern.output(sorted);
}
