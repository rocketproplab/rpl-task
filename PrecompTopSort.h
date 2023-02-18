#include <iostream>
#include <vector>
#include "RplTask.h"
#include <string>

vector<RplTask> getDependencies(string path);
vector<RplTask> topologicalSort();
void outputWithOutputStrategy(vector<RplTask> & sorted);
