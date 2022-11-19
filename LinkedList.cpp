#include "LinkedList.h"

template <typename T> int LinkedList<T>::size(){
	return size;
}

template <typename T> void LinkedList<T>::add(T* obj){
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

template <typename T> T* LinkedList<T>::get(int index){
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

template <typename T> void LinkedList<T>::deleteNode(Node* node){
	if(node != nullptr){
		deleteNode(node->next);
	}
	delete node->value;
	delete node;
}

template <typename T> LinkedList<T>::~LinkedList(){
	deleteNode(head);
}
