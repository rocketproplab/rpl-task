#include <regex>
#include "PrecompTopSort.h"

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

/**
* Gets the contents of a file at specified path by reading 
* lines until there are none left
*/
string getFileContents(string path){
	string output;
	bool flag = true;
	ifstream file(path);

	//Read lines from file until there aren't any left
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

/**
* Gets the dependency list of the task
* Does this via seeing what is between the two tags and 
* placing them in a list
*/
vector<string> getDependencies(string fileContents){	
	vector<string> dependencies;

	string rplString= "TASK-DEPENDENCIES" ;
	int rplSize = rplString.size() + 1; 
	int startIndex = fileContents.find(rplString) + rplSize;

	string newString = fileContents.substr(startIndex) ;
	string line = newString.substr(0,newString.find('\n')) ;

	//Get everything in between the two tags
	while (line != "END-TASK-DEPENDENCIES") {
		dependencies.push_back(line) ;
		newString = newString.substr(newString.find('\n') + 1) ;
		line = newString.substr(0,newString.find('\n')) ;
	}

	return dependencies;
}

/**
* Use regex to get the task name setting in the header and returns its value
*/
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

/**
* Use regex to get the start on boot setting in the header and returns its value
*/
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

/**
* Topological sort of a graph via depth first search
* this functiuon is primarily to keep track of the nodes that have been visited
* with temp and permanent marks
*/
vector<string> topologicalSort(Graph & g){
	vector<string> topologicalOrdering;
	unordered_set<string> permanentMarks; 
	unordered_set<string> temporaryMarks; 
	

	for (auto element: g) {
		visit(element.first,temporaryMarks,permanentMarks,topologicalOrdering,g);
	}

		

	return topologicalOrdering; 
}

/**
* Subroutine for the topological sort. Preforms a recursive depth first search to get the order of the tasks
* Throws an error if the graph given has a cycle
*/
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

/**
* Takes in a sorted list of tasks and applies the specified output strategy to generate code
*/
void outputWithOutputStrategy(vector<Task> & sorted, IOutputStrategyPattern* pattern){
	pattern->output(sorted);
}
