#pragma once

#include <vector>

#include "linkedList.h"

template <class T, class Key = T>
class HashTable {
private:
	static const int defaultHashTableSize;
	static const float resizeIndex;

	LinkedList<T, Key>* buckets;
	std::size_t numBuckets;
	std::size_t numElements;

	void resizeTable();
public:
	HashTable(const int = defaultHashTableSize);

	void insert(const T&, const Key&);
	T* getValue(const Key&) const;

	~HashTable();
};
