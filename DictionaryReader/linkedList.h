#pragma once

#include "dictionaryWord.h"

template <class T, class Key = T>
class LinkedList {
private:
	struct Node {
		Node(const T&);
		T data;
		Node* next;
	};

	Node* head;
	Node* tail;
	
	void deleteList();
public:
	LinkedList();

	void insert(const T&);
	void remove(const Key&);
	T* getNode(const Key&) const;

	~LinkedList();
};
