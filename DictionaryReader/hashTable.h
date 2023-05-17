#pragma once

#include <vector>

#include "linkedList.h"

class HashTable {
private:
	static const int defaultHashTableSize;
	static const float resizeIndex;

	LinkedList* buckets;
	unsigned long numBuckets;
	unsigned long numElements;

	unsigned long hashFunction(const std::string&) const;
	void resizeTable();
public:
	HashTable(const int = defaultHashTableSize);

	void insert(const DictionaryWord&);
	DictionaryWord* getValue(const std::string&) const;

	~HashTable();
};
