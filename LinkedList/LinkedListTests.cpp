// Include the Catch2 testing framework
#include <catch.hpp>

// Include the Node and LinkedList headers needed to test
#include "LinkedList.h"
#include "Node.h"

TEST_CASE("A Linked list can be created and used") {
	SECTION("Lists hold whatever type they are created with") {
		LinkedList<int> intList;
		LinkedList<float> floatList;
		LinkedList<bool> boolList;
		LinkedList<std::string> stringList;
	}
}