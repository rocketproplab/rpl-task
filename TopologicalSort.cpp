#include "TopologialSort.h"
#include <stdexcept>

TaskLinkedList topologicalSort(Graph graph){
	TaskLinkedList outputReverse;
	TaskLinkedList unvisited;
	TaskLinkedList::Node current = graph.labels.head;
	while(current != nullptr){
		unvisited.add(current);
		current = current.next;
	}
	
	while(unvisited.size() != 0){
		visit(unvisited.get(0), graph, &outputReverse);
	}
	
	TaskLinkedList output;	
	for(int i = outputReverse.getSize()-1; i >=  0; --i){
		output.add(outputReverse.get(i));
	}
	return arrayOut;
}

void visit(RplTask* task, Graph graph, TaskLinkedList* outputReverse){
	if(graph.permanentMarks.contains(task)){
		return;
	}
	if(graph.temporaryMarks.contains(task)){
		throw std::invalid_argument("graph has cycle");
	}

	graph.temporaryMarks.add(task);
	
	for(RplTask* neighbor : *(graph.graph + labels.getIndex(task))){
		visit(neighbor);
	}	

	graph.temporaryMarks.removeTask(task);
	graph.permanentMarks.add(task);
	outputReverse->add(task);
}

