#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
	Node() {
		_nextNode = nullptr;
		_prevNode = nullptr;
	}
	
	Node(T data) {
		_data = data;
		_nextNode = nullptr;
		_prevNode = nullptr;
	}

	void setData(T newData) {
		_data = newData;
	}

	T getData() {
		return _data;
	}

	void setNextNode(Node<T>* nextNode) {
		_nextNode = nextNode;
	}

	void setPrevNode(Node<T>* prevNode) {
		_prevNode = prevNode;
	}

	Node<T>* getNextNode() {
		return _nextNode;
	}

	Node<T>* getPrevNode() {
		return _prevNode;
	}

private:
	T _data;
	Node<T>* _nextNode;
	Node<T>* _prevNode;
};

#endif // !NODE_H