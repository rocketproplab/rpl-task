#include "TaskLinkedList.h"
#include "RplTask.h"

struct Graph{
	public:
		TaskLinkedList labels; // Adjacency list. All elements will be deleted by the destructor. 
		TaskLinkedList temporaryMarks; //Leave empty b4 topo-sort (preorder)
		TaskLinkedList permanentMarks; //Leave empty b4 topo-sort (postorder)
		int size; //num nodes
		TaskLinkedList* graph; 
		~Graph() ; // Delete dynamically allocated elements in the adjacency list. 
};

TaskLinkedList topologicalSort(Graph &graph);
void visit(RplTask* task, Graph &graph, TaskLinkedList * outputReverse);

