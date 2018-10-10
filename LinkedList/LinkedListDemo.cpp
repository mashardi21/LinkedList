#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<int> intList;
	int userValue;

	cout << "Welcome to my Linked List Demo" << endl;

	cout << "Initializing and populating the list..." << endl;
	for (int i = 0; i < 5; i++) {
		intList.insertNode(i + 1);
	}

	cout << "The list has been populated:" << endl;
	cout << "\t" << intList << endl;
	cout << endl;

	system("PAUSE");
	system("CLS");

	cout << "New nodes can be added to the list." << endl;
	cout << "Please enter a number to store in the list: ";
	cin >> userValue;
	cin.ignore();

	system("CLS");

	cout << "Adding node to list..." << endl;

	intList.insertNode(userValue);

	cout << "Node added:" << endl;
	cout << "\t" << intList << endl;

	system("PAUSE");
	system("CLS");

	cout << "Nodes can also be searched for" << endl;

	system("PAUSE");
	return 0;
}