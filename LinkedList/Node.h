#ifndef NODE.H
#define NODE.H

template <class T>
class Node {
public:
	Node(T data) {
		_data = data;
		_nextNode = nullptr;
		_prevNode = nullptr;
	}
	~Node() {

	}
	T getData() {
		return _data;
	}
	void setNextNode(T* nextNode) {
		_nextNode = nextNode;
	}
	void setPrevNode(T* prevNode) {
		_prevNode = prevNode;
	}
	T* getNextNode() {
		return _nextNode;
	}
	T* getPrevNode() {
		return _prevNode;
	}
private:
	T _data;
	T* _nextNode;
	T* _prevNode;
};

#endif // !NODE.H