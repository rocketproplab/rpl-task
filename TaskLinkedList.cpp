#include "TaskLinkedList.h"
#include <iostream>

using namespace std;

int TaskLinkedList::getSize(){
	return size;
}

void TaskLinkedList::add(RplTask* obj){
	Node* newNode = new Node();
	newNode->value = obj;	
	cout << "here1" << endl;
	if(tail == nullptr){
		cout << "here2" << endl;
		head = newNode;
		tail = newNode;		
		size++;	
	}else{
		tail->next = newNode;
		size++;
		tail = tail->next;
	}
	cout << "here3" << endl;
}

void TaskLinkedList::deleteTask(RplTask* task){
	if(size == 0){
		return;
	}
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
	if(node != nullptr){
		deleteNode(node->next);
		delete node->value;
		delete node;
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

TaskLinkedList::~TaskLinkedList(){
	deleteNode(head);
}

