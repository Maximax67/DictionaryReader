#pragma once

#include "dictionaryWord.h"

class Node {
private:
	DictionaryWord data;
	Node* next;
public:
	Node(const DictionaryWord&);
	DictionaryWord& getData();
	Node* getNext() const;
	void setData(const DictionaryWord&);
	void setNext(Node*);
};
