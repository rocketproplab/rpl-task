#include <iostream>
#include <vector>
#include "RplTask.h"
#include <string>

typedef unorder_map<string, vector<string>> Graph;
vector<string> getDependencies(string path);
vector<string> topologicalSort(Graph & g);
string getTaskName(string path);
void outputWithOutputStrategy(vector<string> & sorted);

