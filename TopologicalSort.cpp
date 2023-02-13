#include "TopologicalSort.h"
#include <stdexcept>

Graph::~Graph() {
	labels.deleteList() ; 

}

TaskLinkedList topologicalSort(Graph & graph){
	TaskLinkedList outputReverse;
	TaskLinkedList unvisited;
	TaskLinkedList::Node* current = graph.labels.head;
	while(current != nullptr){
		unvisited.add(current->value);
		current = current->next;
	}

	
for (int i = 0 ; i < unvisited.getSize() ; ++i) {
	visit(unvisited.get(i), graph, &outputReverse);
}


	TaskLinkedList output;	
	
	for(int i = outputReverse.getSize()-1; i >=  0; --i){
		output.add(outputReverse.get(i));
	}
	
	return output;
}

void visit(RplTask* task, Graph & graph, TaskLinkedList* outputReverse){
	
	if(graph.permanentMarks.contains(task)){
		return;
	}

	if(graph.temporaryMarks.contains(task)){
		throw std::invalid_argument("graph has cycle");
	}

	graph.temporaryMarks.add(task);

 	TaskLinkedList* neighborList = (graph.graph + graph.labels.getIndex(task));
 	int numNeighbors = neighborList->getSize();

	
	
	if (numNeighbors > 0) {
	for(int i = 0; i < numNeighbors; ++i){
 		RplTask* neighbor = neighborList->get(i);
		visit(neighbor, graph, outputReverse);
	}	
	}

	/*
	Instead of deleting the RPLTask, which was causing SEG issues since other items were pointing at it ,
	creating a new function which simply removed it from the Linked List w/o deleting the task off the heap.
	*/
	graph.temporaryMarks.removeTask(task) ; 

	graph.permanentMarks.add(task); 

	
	outputReverse->add(task);
}

