using namespace std;

template <typename T> class LinkedList {
private:
	int size;
	void deleteNode(Node* node);
	Node* head;
	Noe* tail;
public:
	class Node{
	public:
		Node* next;
		T* value;
		Node() : next(nullptr), value(nullptr){}
	}
	int size();
	T* get(int index);
	void deleteIndex(int index);
	LinkedList() : head(nullptr), tail(nullptr), size(0){}
	~LinkedList();
	void add(T* obj);
};
