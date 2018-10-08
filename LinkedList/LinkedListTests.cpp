#include <string>

// Include the Catch2 testing framework
#include <catch.hpp>

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

