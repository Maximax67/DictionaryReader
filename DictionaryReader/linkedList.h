#pragma once

#include "node.h"

class LinkedList {
private:
	Node* head;
	Node* tail;
	
public:
	LinkedList();

	void insert(const DictionaryWord&);
	void remove(const std::string&);
	DictionaryWord* getValue(const std::string&) const;
	Node* getHeadNode() const;

	~LinkedList();
};
