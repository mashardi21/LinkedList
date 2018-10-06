#ifndef NODE.H
#define NODE.H

template <class T>
class Node {
public:
	Node(T data);
	~Node();
	T getData();
	void setNextNode(T* nextNode);
	void setPrevNode(T* prevNode);
	T* getNextNode();
	T* getPrevNode();
private:
	T _data;
	T* _nextNode;
	T* _prevNode;
};

#endif // !NODE.H