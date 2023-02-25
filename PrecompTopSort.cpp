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

vector<string> sorted  = topologicalSort(graph);


	outputWithOutputStrategy(sorted);	
	return 0;
}

vector<string> getDependencies(string path){
	//TODO	
	vector<string> dependencies ;

	return dependencies ; 
}


string getTaskName(string path){
	//TODO
	string taskName = "" ;

	return taskName ; 
}


vector<string> topologicalSort(Graph & g){
	//TODO	

	vector<string> topologicalOrdering ;
	unordered_set<string> permanentMarks ; 
	unordered_set<string> temporaryMarks ; 
	
	

	for (auto element: g) {
		visit(element.first,temporaryMarks,permanentMarks,topologicalOrdering,g) ;
		}

	return topologicalOrdering ; 
}

void visit(string task, unordered_set<string> & temporaryMarks, unordered_set<string> & permanentMarks, vector<string> & topologicalOrder, Graph & g ) {

	if (permanentMarks.find(task) != permanentMarks.end() ) {
		return ; 
	}

	else if (temporaryMarks.find(task) != temporaryMarks.end()) {
		throw std::invalid_argument("Graph has cycle");
	}

	temporaryMarks.insert(task) ;

	for (auto adjacentNodes : g[task]) {
		visit(adjacentNodes, temporaryMarks, permanentMarks, topologicalOrder, g) ;
	}

	temporaryMarks.erase(task) ;
	permanentMarks.insert(task) ;

	topologicalOrder.insert(topologicalOrder.begin(),task) ;


}

void outputWithOutputStrategy(vector<string> & sorted){
	//TODO	
}
