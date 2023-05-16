#pragma once

#include "node.h"

template <class T, class Key = T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	
public:
	LinkedList();

	void insert(const T&);
	void remove(const Key&);
	T* getValue(const Key&) const;
	Node<T>* getHeadNode() const;

	~LinkedList();
};
