#include "linkedList.h"

#include <string>

template <class T, class Key>
LinkedList<T, Key>::Node::Node(const T& value) : data(value), next(nullptr) {};

template <class T, class Key>
LinkedList<T, Key>::LinkedList() : head(nullptr), tail(nullptr) {};

template <class T, class Key>
LinkedList<T, Key>::~LinkedList() {
    deleteList();
}

template <class T, class Key>
void LinkedList<T, Key>::insert(const T& value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <class T, class Key>
void LinkedList<T, Key>::remove(const Key& value) {
    if (head == nullptr) {
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            if (current->next == nullptr) {
                tail = current;
            }
            delete temp;
            return;
        }
        current = current->next;
    }
}

template <class T, class Key>
void LinkedList<T, Key>::deleteList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

template <class T, class Key>
typename T* LinkedList<T, Key>::getNode(const Key& key) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return &current->data;
        }
        current = current->next;
    }
    return nullptr;
}

template class LinkedList<DictionaryWord, std::string>;
