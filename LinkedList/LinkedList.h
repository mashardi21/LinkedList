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

	// OverLoaded copy constructor to allow for a deep copy
	LinkedList(const LinkedList<T>& copiedList) {
		_listSize = 0;
		_headPtr = nullptr;
		_tailPtr = nullptr;
		*this = copiedList;
	}

	// Overloaded operator= for creating deep copies
	const LinkedList<T>& operator=(const LinkedList<T>& otherList) {
		if (this != &otherList) {
			if (_headPtr != nullptr) {
				clearList();
			}

			Node<T>* copyNode = nullptr;
			Node<T>* otherNode = otherList._headPtr;

			while (otherNode != nullptr) {
				if (_headPtr == nullptr) {
					copyNode = new Node<T>(otherNode->getData());
					_headPtr = copyNode;
					_tailPtr = copyNode;
					otherNode = otherNode->getNextNode();
					_listSize++;
				}
				else {
					copyNode->setNextNode(new Node<T>(otherNode->getData()));
					copyNode = copyNode->getNextNode();
					copyNode->setPrevNode(_tailPtr);
					_tailPtr = copyNode;
					otherNode = otherNode->getNextNode();
					_listSize++;
				}
			}
		}

		return *this;
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

	// Getters for headPtr, tailPtr, and listsize
	Node<T>* getHeadPtr() {
		return _headPtr;
	}

	Node<T>* getTailPtr() {
		return _tailPtr;
	}

	int getListSize() {
		return _listSize;
	}

	// this function inserts a new node at the tail of the list that contains the user-provided value
	void insertNode(T newData) {
		if (newData == NULL) {
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

	// This function deletes a node found at the provided memory address
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

	// This function deletes every node in the list without deleteing the list object itself
	void clearList() {
		Node<T>* currentNode = _headPtr;

		Node<T>* nextNode = currentNode->getNextNode();

		while (currentNode != nullptr) {
			deleteNode(currentNode);
			currentNode = nextNode;
			
			if (nextNode != nullptr) {
				nextNode = nextNode->getNextNode();
			}
		}
	}

	// Find the first node that contains the requested data and return a pointer to it
	//
	// ***IMPORTANT: IF THE LIST CONTAINS MULTIPLE NODES WITH THE SAME DATA, ONLY THE FIRST 
	//    NODE WITH MATCHING DATA WILL BE RETURNED. I WAS UNABLE TO FIGURE OUT HOW TO FIND
	//    DUPLICATES***
	//
	Node<T>* find(T dataToFind) {
		if (dataToFind == NULL) {
			return nullptr;
		}

		Node<T>* currentNode = new Node<T>();
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
	// private vairables for storing the head, tail, and size of the list
	Node<T>* _headPtr;
	Node<T>* _tailPtr;
	int _listSize;

	template<typename T, typename charT, typename traits>
	friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& stream, const LinkedList<T>& list);
};

// Overload the operator<< to allow a lists nodes to be printed with an ostrem, eg. cout << listName << endl;
//
// ***IMPORTANT: IF THE LIST IS STORING A USER-CREATED TYPE, THAT TYPE MUST HAVE AN OVERLOADED operator<< ***
template<typename T, typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& Stream, const LinkedList<T>& list) {
	Node<T>* currentNode = list._headPtr;

	if (currentNode == nullptr) {
		Stream << "";
	}
	else {
		for (currentNode; currentNode != nullptr; currentNode = currentNode->getNextNode()) {
			if (currentNode->getNextNode() == nullptr) {
				Stream << currentNode->getData();
			}
			else {
				Stream << currentNode->getData() << ", ";
			}
		}
	}

	return Stream;
}

#endif // !LINKEDLIST_H