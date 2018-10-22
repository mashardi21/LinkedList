#include <iostream>

#include "LinkedList.h"

using namespace std;

void clearScreen() {
	system("PAUSE");
	system("CLS");
}

int main() {
	LinkedList<int> intList;
	int userValue;

	cout << "Welcome to my Linked List Demo" << endl;

	cout << "Initializing and populating the list..." << endl;
	for (int i = 0; i < 5; i++) {
		intList.insertNode(i + 1);
	}

	cout << "The list has been populated:" << endl;
	cout << "\tList: " << intList << endl;
	cout << endl;

	clearScreen();

	cout << "New nodes can be added to the list." << endl;
	cout << "Please enter a number to store in the list: ";
	cin >> userValue;
	cin.ignore();

	system("CLS");

	cout << "Adding node to list..." << endl;

	intList.insertNode(userValue);

	cout << "Node added" << endl;
	cout << "\tList: " << intList << endl;

	clearScreen();

	cout << "Nodes can also be searched for" << endl;

	cout << "Please enter a vlue to search the list for: ";
	cin >> userValue;
	cin.ignore();

	Node<int>* foundNode = intList.find(userValue);

	if (foundNode == nullptr) {
		cout << endl << "There are no nodes that contain that value" << endl;
	}
	else {
		cout << endl << "The node containing the value " << userValue << " was found at memory address " << foundNode << endl;
	}

	clearScreen();

	cout << "Nodes can be deleted" << endl;
	cout << "Please enter the value you would like to delete from the list: ";
	cin >> userValue;
	cin.ignore();

	foundNode = intList.find(userValue);
	
	if (foundNode == nullptr) {
		cout << endl << "There are no nodes that contain that value" << endl;
	}
	else {
		intList.deleteNode(foundNode);
		cout << "The node has been deleted" << endl;
		cout << "\tList: " << intList << endl;
	}

	clearScreen();

	cout << "The list can be cleared" << endl;

	system("PAUSE");

	cout << "Clearing list..." << endl;
	
	intList.clearList();

	cout << "The list has been cleared" << endl;
	cout << "\tList: " << intList << endl;

	clearScreen();

	cout << "Thank you for using the demo." << endl;

	system("PAUSE");
	return 0;
}