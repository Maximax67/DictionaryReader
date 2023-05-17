#include "hashTable.h"

const int HashTable::defaultHashTableSize = 10;

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
	std::size_t index = std::hash<std::string>{}(value.getWord()) % numBuckets;
	
	buckets[index].insert(value);
	numElements++;

	if (numElements > numBuckets * resizeIndex) {
		resizeTable();
	}
}

DictionaryWord* HashTable::getValue(const std::string& key) const {
	std::size_t index = std::hash<std::string>{}(key) % numBuckets;
	return buckets[index].getValue(key);
}

void HashTable::resizeTable() {
	std::size_t newSize = numBuckets * 2;
	LinkedList* newBuckets = new LinkedList[newSize];

	for (std::size_t i = 0; i < numBuckets; i++) {
		Node* cur = buckets[i].getHeadNode();
		while (cur != nullptr) {
			std::size_t newIndex = std::hash<std::string>{}(cur->getData().getWord()) % newSize;
			newBuckets[newIndex].insert(cur->getData());
			cur = cur->getNext();
		}
	}

	delete[] buckets;

	buckets = newBuckets;
	numBuckets = newSize;
}
