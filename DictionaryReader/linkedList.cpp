#include "linkedList.h"

#include <string>

template <class T, class Key>
LinkedList<T, Key>::LinkedList() : head(nullptr), tail(nullptr) {};

template <class T, class Key>
LinkedList<T, Key>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->getNext();
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
};

template <class T, class Key>
void LinkedList<T, Key>::insert(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template <class T, class Key>
void LinkedList<T, Key>::remove(const Key& value) {
    if (head == nullptr) {
        return;
    }

    if (head->getData() == value) {
        Node<T>* temp = head;
        head = head->getNext();
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return;
    }

    Node<T>* current = head;
    while (current->getNext() != nullptr) {
        if (current->getNext()->getData() == value) {
            Node<T>* temp = current->getNext();
            current->setNext(current->getNext()->getNext());
            if (current->getNext() == nullptr) {
                tail = current;
            }
            delete temp;
            return;
        }
        current = current->getNext();
    }
}

template <class T, class Key>
typename T* LinkedList<T, Key>::getValue(const Key& key) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->getData() == key) {
            return &current->getData();
        }
        current = current->getNext();
    }
    return nullptr;
}

template <class T, class Key>
typename Node<T>* LinkedList<T, Key>::getHeadNode() const {
    return head;
}

template class LinkedList<DictionaryWord, std::string>;
