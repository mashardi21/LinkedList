#include <iostream>
#include <string>

#include "LinkedList.h"

using namespace std;

template<typename T>
void printList(LinkedList<T>& list1) {
	Node<T>* currentNode = list1.getHeadPtr();

	while (currentNode != nullptr) {
		cout << currentNode->getData() << ", ";
		currentNode = currentNode->getNextNode();
	}
	cout << endl << endl;
}

int main() {
	// Create three linked lists that store different types
	LinkedList<int> intList;
	LinkedList<string> stringList;

	cout << "Welcome to my Linked List Demo" << endl;

	stringList.insertNode("one");
	stringList.insertNode("two");
	stringList.insertNode("tree");
	stringList.insertNode("four");
	stringList.insertNode("five");

	for (int i = 0; i < 5; i++) {
		intList.insertNode(i + 1);
	}

	printList(intList);
	printList(stringList);

	system("PAUSE");
	return 0;
}