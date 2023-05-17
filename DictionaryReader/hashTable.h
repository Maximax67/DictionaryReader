#pragma once

#include <vector>

#include "linkedList.h"

class HashTable {
private:
	static const int defaultHashTableSize;
	static const float resizeIndex;

	LinkedList* buckets;
	std::size_t numBuckets;
	std::size_t numElements;

	void resizeTable();
public:
	HashTable(const int = defaultHashTableSize);

	void insert(const DictionaryWord&);
	DictionaryWord* getValue(const std::string&) const;

	~HashTable();
};
