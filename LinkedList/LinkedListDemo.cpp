#include <iostream>
#include <string>

#include "LinkedList.h"

using namespace std;

struct someObject
{
	int someData;
	string description;
	bool isUseful;
};

int main() {
	LinkedList<int> intList;
	LinkedList<string> stringList;
	LinkedList<someObject> objectList;

	cout << "Welcome to my Linked List Demo" << endl;

	system("PAUSE");
	return 0;
}