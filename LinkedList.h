using namespace std;

template <typename T> class LinkedList {
private:
	int size;
	Node* root;
	void deleteNode(Node* node);
public:
	class Node{
	public:
		Node* next;
		T* value;
	}
	int size();
	T* get(int index);
	LinkedList();
	~LinkedList();
	void add(T* obj);
};
