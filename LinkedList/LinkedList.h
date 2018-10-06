#ifndef LINKEDLIST.H
#define LINKEDLIST.H

#include "Node.h"
#include "Node.cpp"

template <class T>
class LinkedList {
public:
	LinkedList() {
		_headPtr = nullptr;
		_tailPtr = nullptr;
	}
	~LinkedList() {

	}
	Node<T>* Find(T dataToFind) {
		Node<T>* currentNode = *_headPtr;

		while (currentNode->getNextNode() != nullptr) {
			if (currentNode->getData() == dataToFind) {
				return &currentNode;
			}
			else {
				currentNode = currentNode->getNextNode();
			}
		}

		return nullptr;
	}
	void insertNode(T newData) {
		Node<T> newNode = Node<T>(newData);
		Node<T>* nodePtr = &newNode;

		if (_headPtr == nullptr) {
			_headPtr = nodePtr;
			_tailPtr = nodePtr;
		}
		else if (_headPtr != nullptr) {
			newNode.setPrevNode(_tailPtr);
			newNode.setNextNode(nullptr);
			_tailPtr->setNextNode(&newNode);
			_tailPtr = &newNode;
		}

		delete nodePtr;
	}
	void deleteNode(Node* delNode) {
		if (_headPtr == nullptr || delNode->getPrevNode() == nullptr) {
			return;
		}

		if (&delnode == &_headPtr) {
			_headPtr = delNode->getNextNode();
			_headPtr->setPrevNode(nullptr);
		}
		else if (&delNode == &_tailPtr) {
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
	}

private:
	Node* _headPtr;
	Node* _tailPtr;

};

#endif // !LINKEDLIST.H