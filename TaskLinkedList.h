#pragma once

class RplTask;

class TaskLinkedList {
public:
	class Node{
	public:
		Node* next;
		RplTask* value;
		Node() : next(nullptr), value(nullptr){}
	};
	
	/**
	* Returns the size of the linked list
	*/
	int getSize();


	/**
	* adds the task to the end of the linked list
	*/
	void add(RplTask* obj);


	/**
	* Returns the element at specified index
	*/
	RplTask* get(int index);


	/**
	* Returns true if element is in linkedlist
	*/
	bool contains(RplTask* task);


	/**
	* Gets the index of an element (-1) if doesn't exist
	*/
	int getIndex(RplTask* task);


	/**
	* Deletes element from linked list if it exists
	*/
	void deleteTask(RplTask* task);

	/**
	* Helper function clear memory
	*/
	void deleteNode(Node* node);

	/**
	* Constructor for empty linked list
	*/
	TaskLinkedList() : size(0), head(nullptr), tail(nullptr) {};

	int size;
	Node* head;
	Node* tail;
	~TaskLinkedList();
};
