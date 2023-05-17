#include "hashTable.h"

const int HashTable::defaultHashTableSize = 100;

const float HashTable::resizeIndex = 0.8f;

HashTable::HashTable(const int startSize) {
	if (startSize <= 0) {
		throw std::invalid_argument("Start size can't be less or equal to 0");
	}

	if (startSize > 1e6) {
		throw std::invalid_argument("Too large start size (>1e6)");
	}
	
	numBuckets = startSize;
	numElements = 0;
	buckets = new LinkedList[startSize];
};

HashTable::~HashTable() {
	delete[] buckets;
};

void HashTable::insert(const DictionaryWord& value) {
	unsigned long index = hashFunction(value.getWord()) % numBuckets;
	
	buckets[index].insert(value);
	numElements++;

	if (numElements > numBuckets * resizeIndex) {
		resizeTable();
	}
}

DictionaryWord* HashTable::getValue(const std::string& key) const {
	unsigned long index = hashFunction(key) % numBuckets;
	return buckets[index].getValue(key);
}

void HashTable::resizeTable() {
	unsigned long newSize = numBuckets * 2;
	LinkedList* newBuckets = new LinkedList[newSize];

	for (unsigned long i = 0; i < numBuckets; i++) {
		Node* cur = buckets[i].getHeadNode();
		while (cur != nullptr) {
			unsigned long newIndex = hashFunction(cur->getData().getWord()) % newSize;
			newBuckets[newIndex].insert(cur->getData());
			cur = cur->getNext();
		}
	}

	delete[] buckets;

	buckets = newBuckets;
	numBuckets = newSize;
}

// djb2 хеш функція
unsigned long HashTable::hashFunction(const std::string& str) const {
	unsigned long hash = 5381;
	int c, i = 0;

	while (c = str[i++])
		hash = ((hash << 5) + hash) + c; // hash * 33 + c

	return hash;
}
