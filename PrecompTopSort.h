#include <iostream>
#include <vector>
//#include "RplTask.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
<<<<<<< HEAD

using namespace std;

typedef unordered_map<string, vector<string>> Graph;
vector<string> topologicalSort(Graph & g);
string getTaskName(string contents);
string getFileContents(string path);
vector<string> getDependencies(string path); // Reads in from the path and outputs the dependencies 
vector<string> topologicalSort(Graph & g); // Needs to be implemented similarish to old one
void visit(string task, unordered_set<string> & temporaryMarks, unordered_set<string> & permanentMarks, vector<string> & topologicalOrder, Graph & g ) ;
void outputWithOutputStrategy(vector<string> & sorted); // Use the strategy (from Trello board) for the output order

