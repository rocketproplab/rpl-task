//#include "RplTask.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "iOutputStrategyPattern.h"

using namespace std;
/*
struct {
	string className;
	bool startOnBoot;
} Task;
*/


typedef unordered_map<string, vector<string>> Graph;

vector<string> topologicalSort(Graph & g);
string getTaskName(string contents);
bool isTaskStartOnBoot(string contents);
string getFileContents(string path);
vector<string> getDependencies(string fileContents); // Reads in from the path and outputs the dependencies 
vector<string> topologicalSort(Graph & g); // Needs to be implemented similarish to old one
void visit(string task, unordered_set<string> & temporaryMarks, unordered_set<string> & permanentMarks, vector<string> & topologicalOrder, Graph & g ) ;
void outputWithOutputStrategy(vector<Task> & sorted, iOutputStrategyPattern pattern); // Use the strategy (from Trello board) for the output order

