#include "RplTask.h"

class TaskLinkedList {
public:
	class Node{
	public:
		Node* next;
		RplTask* value;
		Node() : next(nullptr), value(nullptr){}
	};
	int getSize();
	void add(RplTask* obj);
	RplTask* get(int index);
	void deleteIndex(int index);
	TaskLinkedList() : size(0), head(nullptr), tail(nullptr) {};
	int size;
	void deleteNode(Node* node);
	Node* head;
	Node* tail;
	~TaskLinkedList();
};
