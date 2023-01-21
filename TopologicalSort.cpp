#include "TopologialSort.h"
#include <stdexcept>

RplTask[] topologicalSort(Graph graph){
	TaskLinkedList output;
	TaskLinkedList unvisited;
	TaskLinkedList::Node current = graph.labels.head;
	while(current != nullptr){
		unvisited.add(current);
		current = current.next;
	}
	
	while(unvisited.size() != 0){
		visit(unvisited.get(0), graph, &output);
	}
	
	RplTask arrayOut[graph.size];
	for(int i = 0; i < graph.size; ++i){
		arrayOut[graph.size - i - 1] = output.get(i);
	}
	return arrayOut;
}

void visit(RplTask* task, Graph graph, TaskLinkedList* output){
	if(graph.permanentMarks.contains(task)){
		return;
	}
	if(graph.temporaryMarks.contains(task)){
		throw std::invalid_argument("graph has cycle");
	}

	graph.temporaryMarks.add(task);
	
	for(RplTask* neighbor : graph.graph[labels.getIndex(task)]){
		visit(neighbor);
	}	

	graph.temporaryMarks.removeTask(task);
	graph.permanentMarks.add(task);
	output->add(task);
}

