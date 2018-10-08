#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
public:
	LinkedList() {
		_headPtr = nullptr;
		_tailPtr = nullptr;
	}
	~LinkedList() {
		Node<T>* currentNode = _headPtr;

		while (currentNode != nullptr) {
			Node<T>* nextNode = currentNode->getNextNode();
			delete currentNode;
			currentNode = nextNode;
		}

	}
	Node<T>* Find(T dataToFind) {
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
	void insertNode(T newData) {
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

	}
	void deleteNode(Node<T>* delNode) {
		if (_headPtr == nullptr || delNode->getPrevNode() == nullptr) {
			return;
		}

		if (delNode == _headPtr) {
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
	}

private:
	Node<T>* _headPtr;
	Node<T>* _tailPtr;
};

#endif // !LINKEDLIST_H