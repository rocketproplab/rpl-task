#include "TaskLinkedList.h"

int TaskLinkedList::getSize(){
	return size;
}

void TaskLinkedList::add(RplTask* obj){
	Node* newNode = new Node();
	newNode->value = obj;	
	if(tail == nullptr){
		head = newNode;
		tail = newNode;		
		size++;	
	}else{
		tail->next = newNode;
		size++;
	}
}

RplTask* TaskLinkedList::get(int index){
	if(size == 0){
		return nullptr;
	}
	Node* curr = head;
	int currIdx = 0;
	while(curr != nullptr && currIdx < index){
		curr = curr->next;
		currIdx++;
	}
	return curr->value;
}

void TaskLinkedList::deleteNode(Node* node){
	if(node != nullptr){
		deleteNode(node->next);
		delete node->value;
		delete node;
	}
}

// TaskLinkedList::TaskLinkedList(){

// }

TaskLinkedList::~TaskLinkedList(){
	deleteNode(head);
}

