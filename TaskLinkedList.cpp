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

// TaskLinkedList::TaskLinkedList(){

// }

TaskLinkedList::~TaskLinkedList(){
	deleteNode(head);
}

