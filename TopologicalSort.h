#include "TaskLinkedList.h"
#include "RplTask.h"

struct Graph{
	public:
		TaskLinkedList labels;
		TaskLinkedList temporaryMarks; //Leave empty b4 topo-sort
		TaskLinkedList permanentMarks; //Leave empty b4 topo-sort
		int size; //num nodes
		TaskLinkedList* graph;
};

TaskLinkedList topologicalSort(Graph graph);
void visit(RplTask* task, Graph graph, TaskLinkedList* output);
