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
	

	/*
	Delete the entire list only once. Must be explicity called to prevent memory leaks.
	Useful because this should prevent the SEGFAULTS of multiple items calling to delete the same node
	that was happen when multiple items were pointing to the same LL nodes and then the destructor was called. 
	
	*/
void deleteList() ;

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

	/*
	Removes from linked list, but does NOT delete the RplTask object.
	Useful for the TopologicalSort and topology
	*/
	void removeTask(RplTask * task) ;


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
