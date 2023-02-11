#include "TaskLinkedList.h"
#include "RplTask.h"

struct Graph{
	public:
		TaskLinkedList labels; // Adjacency list
		TaskLinkedList temporaryMarks; //Leave empty b4 topo-sort // pre order
		TaskLinkedList permanentMarks; //Leave empty b4 topo-sort // post order
		int size; //num nodes
		TaskLinkedList* graph;
};

TaskLinkedList topologicalSort(Graph graph);
void visit(RplTask* task, Graph graph, TaskLinkedList* output);
