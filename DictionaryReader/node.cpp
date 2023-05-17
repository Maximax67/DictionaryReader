#include "node.h"

Node::Node(const DictionaryWord& value) : data(value), next(nullptr) {};

void Node::setData(const DictionaryWord& d) {
	data = d;
}

void Node::setNext(Node* n) {
	next = n;
}

DictionaryWord& Node::getData() {
	return data;
};

Node* Node::getNext() const {
	return next;
};
