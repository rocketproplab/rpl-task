#include "TopologicalSort.h"
#include <stdexcept>

TaskLinkedList topologicalSort(Graph graph){
	TaskLinkedList outputReverse;
	TaskLinkedList unvisited;
	TaskLinkedList::Node* current = graph.labels.head;
	while(current != nullptr){
		unvisited.add(current->value);
		current = current->next;
	}
	
	while(unvisited.getSize() != 0){
		visit(unvisited.get(0), graph, &outputReverse);
	}
	
	TaskLinkedList output;	
	for(int i = outputReverse.getSize()-1; i >=  0; --i){
		output.add(outputReverse.get(i));
	}
	return output;
}

void visit(RplTask* task, Graph graph, TaskLinkedList* outputReverse){
	if(graph.permanentMarks.contains(task)){
		return;
	}
	if(graph.temporaryMarks.contains(task)){
		throw std::invalid_argument("graph has cycle");
	}

	graph.temporaryMarks.add(task);

 	TaskLinkedList* neighborList = (graph.graph + graph.labels.getIndex(task));
 	int numNeighbors = neighborList->getSize();
	for(int i = 0; i < numNeighbors; ++i){
 		RplTask* neighbor = neighborList->get(i);
		visit(neighbor, graph, outputReverse);
	}	

	graph.temporaryMarks.deleteTask(task);
	graph.permanentMarks.add(task);
	outputReverse->add(task);
}

