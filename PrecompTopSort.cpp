#include "PrecompTopSort.h"
#include <tuple>
#include <regex>
#include <fstream>
using namespace std;

//Current syntax for header comment:
/*
RPL-TASK-HEADER
CLASS: Task3
RPL-TASK-DEPENDENCIES
Task1
Task2
END-TASK-DEPENDENCIES
END-HEADER
*/



int main(int argc, char** argv){
	string contents=getFileContents("/Users/varunsreedhar/Desktop/rpl-task/LinkedListTest.h");
	string taskName = getTaskName(contents);
	cout << taskName << endl;
/*
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
*/
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

string getTaskName(string contents){
	//regex expression("(?<=RPL\\-TASK\\-HEADER)(.|\\s)*(?=END\\-HEADER)");
	regex expression("RPL-TASK-HEADER(.|\n)*?END-HEADER");
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

vector<string> getDependencies(string path){
	//TODO	
}


vector<string> topologicalSort(Graph & g){
	//TODO	
}

void outputWithOutputStrategy(vector<string> & sorted){
	//TODO	
}