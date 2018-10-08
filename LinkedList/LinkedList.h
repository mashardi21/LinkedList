#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
public:
	// Default constructor
	LinkedList() {
		_listSize = 0;
		_headPtr = nullptr;
		_tailPtr = nullptr;
	}

	// Copy constructor
	LinkedList(const LinkedList<T> &copiedList) {
		_listSize = 0;
		_headPtr = nullptr;
		_tailPtr = nullptr;

		Node<T> copyNode = Node<T>();
		Node<T> tempNode = *(copiedList.getHeadPtr());

		copyNode.setNextNode(copiedList.getHeadPtr());

		do {
			copyNode = *(copyNode.getNextNode());
			insertNode(copyNode.getData());
			copyNode.setNextNode(tempNode.getNextNode());
			
			if (tempNode.getNextNode() != nullptr) {
				tempNode = *(tempNode.getNextNode());
			}
		} while (copyNode.getNextNode() != nullptr);
	}

	// Destructor
	~LinkedList() {
		Node<T>* currentNode = _headPtr;

		while (currentNode != nullptr) {
			Node<T>* nextNode = currentNode->getNextNode();
			delete currentNode;
			currentNode = nextNode;
		}
	}

	Node<T>* getHeadPtr() {
		return _headPtr;
	}

	Node<T>* getTailPtr() {
		return _tailPtr;
	}

	int getListSize() {
		return _listSize;
	}

	void insertNode(T newData) {
		if (newData == NULL) {
			std::cout << "Cannot have data of NULL. No node was created..." << std::endl;
			return;
		}

		Node<T>* newNode = new Node<T>(newData);

		if (_headPtr == nullptr) {
			_headPtr = newNode;
			_tailPtr = newNode;
		}
		else if (_headPtr != nullptr) {
			newNode->setPrevNode(_tailPtr);
			newNode->setNextNode(nullptr);
			_tailPtr->setNextNode(newNode);
			_tailPtr = newNode;
		}

		_listSize++;
	}

	void deleteNode(Node<T>* delNode) {
		if (_headPtr == nullptr) {
			return;
		}

		if (_listSize == 1) {
			_headPtr = nullptr;
			_tailPtr = nullptr;
		}
		else if (delNode == _headPtr) {
			_headPtr = delNode->getNextNode();
			_headPtr->setPrevNode(nullptr);
		}
		else if (delNode == _tailPtr) {
			_tailPtr = delNode->getPrevNode();
			_tailPtr->setNextNode(nullptr);
		}
		else {
			Node<T>* prevNode = delNode->getPrevNode();
			Node<T>* nextNode = delNode->getNextNode();

			prevNode->setNextNode(nextNode);
			nextNode->setPrevNode(prevNode);
		}

		delete delNode;
		_listSize--;
	}

	// Find the first node that contains the requested data and return a pointer to it
	//
	// ***IMPORTANT: IF THE LIST CONTAINS MULTIPLE NODES WITH THE SAME DATA, ONLY THE FIRST 
	//    NODE WITH MATCHING DATA WILL BE RETURNED. I WAS UNABLE TO FIGURE OUT HOW TO FIND
	//    DUPLICATES***
	//
	Node<T>* Find(T dataToFind) {
		if (dataToFind == NULL) {
			return nullptr;
		}

		Node<T>* currentNode = new Node<T>;
		currentNode->setNextNode(_headPtr);

		while (currentNode != nullptr) {
			if (currentNode->getData() == dataToFind) {
				return currentNode;
			}
			else {
				currentNode = currentNode->getNextNode();
			}
		}

		return nullptr;
	}

private:
	Node<T>* _headPtr;
	Node<T>* _tailPtr;
	int _listSize;
};

#endif // !LINKEDLIST_H