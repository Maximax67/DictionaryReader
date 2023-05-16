#include "node.h"

template <typename T>
Node<T>::Node(const T& value) : data(value), next(nullptr) {};

template <typename T>
void Node<T>::setData(const T& d) {
	data = d;
}

template <typename T>
void Node<T>::setNext(Node<T>* n) {
	next = n;
}

template <typename T>
T& Node<T>::getData() {
	return data;
};

template <typename T>
Node<T>* Node<T>::getNext() const {
	return next;
};

template class Node<DictionaryWord>;
