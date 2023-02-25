#include <iostream>
#include <vector>
#include "RplTask.h"
#include <string>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, vector<string>> Graph;
vector<string> getDependencies(string path);
vector<string> topologicalSort(Graph & g);
string getTaskName(string contents);
string getFileContents(string path);
void outputWithOutputStrategy(vector<string> & sorted);

