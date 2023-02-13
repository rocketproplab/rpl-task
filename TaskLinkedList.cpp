#include "TaskLinkedList.h"
#include "RplTask.h"
#include "iostream"

using namespace std ; 

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
		tail = tail->next;
	}
}

void TaskLinkedList::removeTask(RplTask * task) {
	if (contains(task) == false) {
		return ; 
	}
	
	if (task == head->value) {
		head = head->next ;
		size -- ; 
		return ; 
	}

	Node * cur = head->next;
	Node * prev = head ; 
	Node * next = nullptr ; 

	while (cur != nullptr) {
		if (cur->value == task) {
			prev->next = cur->next ; 
			cur->next = nullptr ;
			return ; 
		}
		prev = cur ;
		cur = cur->next ; 
	}
}

void TaskLinkedList::deleteTask(RplTask* task){
	if(size == 0){
		return;
	}
	cout << "Deleting task inside LL: " << task << endl ; 
	if(head->value == task){
		Node* newHead = head->next;
		delete head->value;
		delete head;	
		head = newHead;	
		size--;
	}else{
		Node* curr = head;
		while(curr->next != nullptr && curr->next->value != task){
			curr = curr->next;
		}
		if(curr->next == nullptr){
			return;
		}
		size--;
		Node* toDelete = curr->next;
		curr->next = toDelete->next;
		delete toDelete->value;
		delete toDelete;
	}
	if(size == 0){
		tail = nullptr;
		head = nullptr;
	}
}

bool TaskLinkedList::contains(RplTask* task){
	Node* curr = head;
	while(curr != nullptr && curr->value != task){
		curr = curr->next;
	}
	if(curr == nullptr){
		return false;
	}
	return true;
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

	if (node != nullptr && size > 0) {
		deleteNode(node->next) ;
		node->next = nullptr ; 
		delete node->value ; 
		delete node ; 
	}
	}


int TaskLinkedList::getIndex(RplTask* task){
	Node* curr = head;
	int counter = 0;
	while(curr != nullptr){
		if(curr->value == task){
			return counter;
		}
		++counter;		
		curr = curr->next;
	}
	return -1;
}

// TaskLinkedList::TaskLinkedList(){

// }

void TaskLinkedList::deleteList() {
	deleteNode(head);

}

TaskLinkedList::~TaskLinkedList(){
	//deleteNode(head); 
	/*
	Calling the destructor was giving segfaults in the graph. 
	Multiple pointers were trying to call the destructor on the same items, which were already deleted. 
	*/
	
	
}

