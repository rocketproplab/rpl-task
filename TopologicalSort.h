#include "TaskLinkedList.h"

struct Graph{
	public:
		TaskLinkedList labels;
		TaskLinkedList temporaryMarks; //Leave empty b4 topo-sort
		TaskLinkedList permanentMarks; //Leave empty b4 topo-sort
		int size; //num nodes
		TaskLinkedList graph[];
};

RplTask[] topologicalSort(Graph graph);
void visit(Rpltask* task, Graph graph, TaskLinkedList* output);
