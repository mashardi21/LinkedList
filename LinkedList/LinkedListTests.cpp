// Include the Catch2 testing framework
#include <catch.hpp>

#include <iostream>

// Include the Node and LinkedList headers needed to test
#include "LinkedList.h"
#include "Node.h"

TEST_CASE("Create a linked list/data type of int/size = 0, headPtr and tailPtr == nullptr", "[Creation]") {
	// This list will be used for all testing
	// Only integers will be tested to reduce the ammount of test code needed
	LinkedList<int> testList;

	//Test to make sure the list was intialized properly
	REQUIRE(testList.getHeadPtr() == nullptr);
	REQUIRE(testList.getTailPtr() == nullptr);
	REQUIRE(testList.getListSize() == 0);
}

TEST_CASE("insertNode/insert at tail/size updates, headPtr and tailPtr point to first and last node, respectively", "[Insertion]") {
	LinkedList<int> testList;
	
	// Get initial values of size, headPtr, and tailPtr to make sure the values have changed after inserting a node
	int initialSize = testList.getListSize();
	Node<int>* initialHead = testList.getHeadPtr();
	Node<int>* initialTail = testList.getTailPtr();

	SECTION("insertNode/attempt to insert NULL instead of a valid node/the function should do nothing") {
		testList.insertNode(NULL);

		REQUIRE(testList.getListSize() == 0);
		
	}

	SECTION("insertNode/add 1 node to empty list/size = 1, headPtr and tailPtr != nullptr and are the same") {
		// Insert 1 node into the list
		testList.insertNode(1);

		// Test that the size, headPtr, and tailPtr were changed
		REQUIRE(testList.getListSize() != initialSize);
		REQUIRE(testList.getHeadPtr() != initialHead);
		REQUIRE(testList.getTailPtr() != initialTail);

		// Test that the size, headPtr, and tailPtr were correctly set
		REQUIRE(testList.getListSize() == 1);
		REQUIRE(testList.getHeadPtr() == testList.getTailPtr());
	}

	SECTION("insertNode/add 5 nodes to empty list/size = 5, headPtr and tailPtr != nullptr and point to first and last node, respectively") {
		// Insert 5 nodes into the list
		for (int i = 0; i < 5; i++) {
			testList.insertNode(i + 1);
		}

		// Test that the size, headPtr, and tailPtr were set to the correct nodes
		// In this case, the first node should contain the integer 1, and the last node shoudl contain 5
		REQUIRE(testList.getListSize() == 5);
		REQUIRE(testList.getHeadPtr()->getData() == 1);
		REQUIRE(testList.getTailPtr()->getData() == 5);
	}
}

TEST_CASE("deleteNode/delete node found at given memory address/size updates, headPtr/tailPtr updated if necessary", "[Deletion]") {
	LinkedList<int> testList;

	SECTION("deleteNode/attempt to delete node from empty list/size, headPtr, and tailPtr remain unchaged") {
		// Obtain the original values for comparison
		int initialSize = testList.getListSize(); // == 0
		Node<int>* initialHead = testList.getHeadPtr(); // == nullptr
		Node<int>* initialTail = testList.getTailPtr(); // == nullptr

		Node<int>* foundAddr = testList.Find(1); // == nullptr
		testList.deleteNode(foundAddr);

		REQUIRE(testList.getListSize() == initialSize);
		REQUIRE(testList.getHeadPtr() == initialHead);
		REQUIRE(testList.getTailPtr() == initialTail);

	}

	SECTION("deleteNode/attempt to delete node from a single-node list/size = 0, headPtr and tailPtr = nullptr") {
		testList.insertNode(1);

		Node<int>* foundAddr = testList.Find(1);
		testList.deleteNode(foundAddr);

		// Test that the size, headPtr, and tailPtr are set to the correct values
		REQUIRE(testList.getListSize() == 0);
		REQUIRE(testList.getHeadPtr() == nullptr);
		REQUIRE(testList.getTailPtr() == nullptr);
	}

	SECTION("deleteNode/attempt to delete requested node from the middle of list (not the head, tail, or adjacent to either)/size decrements by 1, nodes before and/or after deleted node update nextNode/prevNode respectively") {
		for (int i = 0; i < 5; i++) {
			testList.insertNode(i + 1);
		}

		int initialSize = testList.getListSize(); // == 5

		// Create pointers to the previous and next nodes for test code simplification
		Node<int>* prevNode = testList.Find(2); 
		Node<int>* nextNode = testList.Find(4);

		Node<int>* foundAddr = testList.Find(3);
		testList.deleteNode(foundAddr);

		// Test that the size decrements by 1, and the previous and next nodes update their nextNode and prevNode pointers, respectively
		REQUIRE(testList.getListSize() == initialSize - 1); // == 4
		REQUIRE(prevNode->getNextNode() == nextNode);
		REQUIRE(nextNode->getPrevNode() == prevNode);
	}

	SECTION("deleteNode/attempt to delete the nodes adjacent to the head and tail of the list/size decrements by 2, middle node updates prevNode and nextNode to point to headPtr/tailPtr respectively, head and tail update nextNode/prevNode to point to middle node") {
		for (int i = 0; i < 5; i++) {
			testList.insertNode(i + 1);
		}

		int initialSize = testList.getListSize(); // == 5
		Node<int>* middleNode = testList.Find(3); // Create pointer to middle node for test code simplification

		Node<int>* foundAddr1 = testList.Find(2);
		Node<int>* foundAddr2 = testList.Find(4);

		testList.deleteNode(foundAddr1);
		testList.deleteNode(foundAddr2);

		// Test that size decrements by 2, the middle node update its prevNode/nextNode pointers to point to the head/tail respectively, and the head and tail updated their nextNode/prevNode pointers respectively
		REQUIRE(testList.getListSize() == initialSize - 2);
		REQUIRE(testList.getHeadPtr()->getNextNode() == middleNode);
		REQUIRE(testList.getTailPtr()->getPrevNode() == middleNode);
		REQUIRE(middleNode->getPrevNode() == testList.getHeadPtr());
		REQUIRE(middleNode->getNextNode() == testList.getTailPtr());
	}

	SECTION("deleteNode/attempt to delete the head and tail nodes from a list/size decrements by 2, headPtr/tailPtr update to the nodes that were adjacent to the head/tail, respectively, new head/tail update their prevNode/nextNode to nullptr") {
		for (int i = 0; i < 5; i++) {
			testList.insertNode(i + 1);
		}

		int initialSize = testList.getListSize(); // == 5;
		Node<int>* adjacentToHead = testList.Find(2);
		Node<int>* adjacentToTail = testList.Find(4);

		Node<int>* foundAddr1 = testList.Find(1);
		Node<int>* foundAddr2 = testList.Find(5);
		
		testList.deleteNode(foundAddr1);
		testList.deleteNode(foundAddr2);

		// Test that size decrements by 2, the headPtr/tailPtr update to the correct nodes, and the new head/tail update their prevNode/nextNode to nullPtr
		REQUIRE(testList.getListSize() == initialSize - 2);
		REQUIRE(testList.getHeadPtr() == adjacentToHead);
		REQUIRE(testList.getTailPtr() == adjacentToTail);
		REQUIRE(testList.getHeadPtr()->getPrevNode() == nullptr);
		REQUIRE(testList.getTailPtr()->getNextNode() == nullptr);
	}

	SECTION("clearList/attempt to delete all nodes from a list without deleteing the list itself/list should start out populated, and end with no nodes, a size of 0, and a _headPtr/_tailPtr == nullptr") {
		for (int i = 0; i < 5; i++) {
			testList.insertNode(i);
		}

		// Get size, _headPtr, and _tailPtr values prior to deletion for comparison
		int initialSize = testList.getListSize();
		Node<int>* intitialHead = testList.getHeadPtr();
		Node<int>* initialTail = testList.getTailPtr();

		testList.clearList();

		// Test the size of the deleted list
		REQUIRE(testList.getListSize() != initialSize);
		REQUIRE(testList.getListSize() == 0);

		// Test the _headPtr of the deleted list
		REQUIRE(testList.getHeadPtr() != intitialHead);
		REQUIRE(testList.getHeadPtr() == nullptr);

		//Test the _tailPtr of the deleted list
		REQUIRE(testList.getTailPtr() != initialTail);
		REQUIRE(testList.getTailPtr() == nullptr);
	}
}

TEST_CASE("Find/locate a node containing the requested data/return a pointer to the found node, return nullptr if not found", "[Finding]") {
	LinkedList<int> testList;

	SECTION("Find/attempt to locate node in empty list/return nullptr") {
		REQUIRE(testList.Find(1) == nullptr);
	}

	SECTION("Find/attempt to locate node that isn't present in list/return nullptr") {
		for (int i = 0; i < 5; i++) {
			testList.insertNode(i + 1);
		}

		REQUIRE(testList.Find(6) == nullptr);
	}

	SECTION("Find/attempt to locate node with data of NULL/return nullptr") {
		for (int i = 0; i < 5; i++) {
			testList.insertNode(i + 1);
		}

		REQUIRE(testList.Find(NULL) == nullptr);
	}

	SECTION("Find/attempt to locate node that is present in list/return address to correct node") {
		for (int i = 0; i < 5; i++) {
			testList.insertNode(i + 1);
		}

		// Test that a pointer was returned
		REQUIRE(testList.Find(4) != nullptr);

		// Test that the returned pointer contains the correct data
		REQUIRE(testList.Find(4)->getData() == 4);
	}

	SECTION("Find/attempt to locate data that is duplicated within the list/only return 1 address the correct node(the first one found)") {
		for (int i = 0; i < 5; i++) {
			testList.insertNode(1);
		}

		// Test that a pointer was returned
		REQUIRE(testList.Find(1) != nullptr);

		// Test that the returned pointer contains the correct data
		REQUIRE(testList.Find(1)->getData() == 1);
	}
}
// This function exists only to prove that the list was copied correctly
bool compareLists(LinkedList<int> &list1, LinkedList<int> &list2) {
	if (&list1 != &list2) {
		Node<int>* list1Current = list1.getHeadPtr();
		Node<int>* list2Current = list2.getHeadPtr();
		int numSameNodes = 0;

		for (int i = 0; i < list1.getListSize(); i++) {
			if (list1Current->getData() == list2Current->getData()) {
				numSameNodes++;
			}

			list1Current = list1Current->getNextNode();
			list2Current = list2Current->getNextNode();
		}

		if (numSameNodes == list1.getListSize() && numSameNodes == list2.getListSize()) {
			return true;
		}
		else {
			return false;
		}
	}
}

TEST_CASE("CopyConstructor and overloaded operator=/create a deep copy of a linked list/copy each node of the list to a node belonging to a new list, creating 2 identical lists", "[Copying]") {
	LinkedList<int> testList;

	for (int i = 0; i < 5; i++) {
		testList.insertNode(i + 1);
	}

	SECTION("CopyConstructor/create a deep copy of a list using the copy constructor and compare the two lists/the lists should be identical (compareLists should return true), but not the same object") {
		LinkedList<int> copiedList = testList;
		
		REQUIRE(compareLists(testList, copiedList));
	}

	SECTION("overloaded operator=/create a deep copy of a list using the overloaded operator= and compare the two lists/the lists should be identical (compareLists should return true), but not the same object") {
		LinkedList<int> copiedList;
		copiedList = testList;

		REQUIRE(compareLists(testList, copiedList));
	}
}