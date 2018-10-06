#ifndef LINKEDLIST.H
#define LINKEDLIST.H

#include "Node.h"
#include "Node.cpp"

template <class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	T* Find(T dataToFind);
	void insertNode(T newData);
	void deleteNode(Node* delNode);

private:
	Node* headPtr;
	Node* tailPtr;

};

#endif // !LINKEDLIST.H