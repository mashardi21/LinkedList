#include "LinkedList.h"
#include "Node.h"
#include "Node.cpp"

template <class T>
LinkedList<T>::LinkedList() {
	headPtr = nullptr;
	tailPtr = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
	delete headPtr;
	delete tailPtr;
}

template <class T>
Node<T>* LinkedList<T>::Find(T dataToFind) {
	Node<T> currentNode = *headPtr;

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

template <class T>
void LinkedList<T>::insertNode(T newData) {
	Node<T> newNode = Node<T>(newData);
	Node<T>* nodePtr = &newNode;

	if (headPtr == nullptr) {
		headPtr = nodePtr;
		tailPtr = nodePtr;
	}
	else if (headPtr != nullptr) {
		newNode.setPrevNode(tailPtr);
		newNode.setNextNode(nullptr);
		tailPtr->setNextNode(&newNode);
		tailPtr = &newNode;
	}

	delete nodePtr;

}

template <class T>
void LinkedList<T>::deleteNode(Node<T>* delNode) {
	if (headPtr == nullptr || delNode->getPrevNode() == nullptr) {
		return;
	}

	if (&delnode == &headPtr) {
		headPtr = delNode->getNextNode();
		headPtr->setPrevNode(nullptr);
	}
	else if (&delNode == &tailPtr) {
		tailPtr = delNode->getPrevNode();
		tailPtr->setNextNode(nullptr);
	}
	else {
		Node<T>* prevNode = delNode->getPrevNode();
		Node<T>* nextNode = delNode->getNextNode();

		prevNode->setNextNode(nextNode);
		nextNode->setPrevNode(prevNode);
	}

	delete delNode;
}