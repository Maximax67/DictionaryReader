#include "hashTable.h"

template <class T, class Key>
const int HashTable<T, Key>::defaultHashTableSize = 10;


template <class T, class Key>
const float HashTable<T, Key>::resizeIndex = 0.8f;


template <class T, class Key>
HashTable<T, Key>::HashTable(const int startSize) {
	if (startSize <= 0) {
		throw std::invalid_argument("Start size can't be less or equal to 0");
	}

	if (startSize > 1e6) {
		throw std::invalid_argument("Too large start size (>1e6)");
	}
	
	numBuckets = startSize;
	numElements = 0;
	buckets = new LinkedList<T, Key>[startSize];
};


template <class T, class Key>
HashTable<T, Key>::~HashTable() {
	delete[] buckets;
};


template <class T, class Key>
void HashTable<T, Key>::insert(const T& value, const Key& key) {
	std::size_t index = std::hash<Key>{}(key) % numBuckets;
	
	buckets[index].insert(value);
	numElements++;

	if (numElements > numBuckets * resizeIndex) {
		resizeTable();
	}
}


template <class T, class Key>
T* HashTable<T, Key>::getValue(const Key& key) const {
	std::size_t index = std::hash<Key>{}(key) % numBuckets;
	return buckets[index].getValue(key);
}


template <class T, class Key>
void HashTable<T, Key>::resizeTable() {
	std::size_t newSize = numBuckets * 2;
	LinkedList<T, Key>* newBuckets = new LinkedList<T, Key>[newSize];

	for (std::size_t i = 0; i < numBuckets; i++) {
		Node<T>* cur = buckets[i].getHeadNode();
		while (cur != nullptr) {
			std::size_t newIndex = std::hash<Key>{}(cur->getData().getWord()) % newSize;
			newBuckets[newIndex].insert(cur->getData());
			cur = cur->getNext();
		}
	}

	delete[] buckets;

	buckets = newBuckets;
	numBuckets = newSize;
}

template class HashTable<DictionaryWord, std::string>;
