#include "Node.h"

template <class T>
Node<T>::Node(T data) {
	_data = data;
	_nextNode = nullptr;
	_prevNode = nullptr;
}

template <class T>
Node<T>::~Node() {
	delete _nextNode;
	delete _prevNode;
}

template <class T>
T Node<T>::getData() {
	return data;
}

template <class T>
void Node<T>::setNextNode(T* nextNode) {
	_nextNode = nextNode;
}

template <class T>
void Node<T>::setPrevNode(T* prevNode) {
	_prevNode = prevNode;
}

template <class T>
T* Node<T>::getNextNode() {
	return _nextNode;
}

template <class T>
T* Node<T>::getPrevNode() {
	return prevNode;
}