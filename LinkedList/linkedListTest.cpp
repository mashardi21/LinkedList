#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main() {
	LinkedList<int> list = LinkedList<int>();

	for (int i = 0; i < 10; i++) {
		list.insertNode(i);
	}

	Node<int>* foundNode;
	foundNode = list.Find(5);

	return 0;
}