#pragma once

#include "dictionaryWord.h"

template<typename T>
class Node {
private:
	T data;
	Node* next;
public:
	Node(const T&);
	T& getData();
	Node* getNext() const;
	void setData(const T&);
	void setNext(Node*);
};
