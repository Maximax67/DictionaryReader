#include "linkedList.h"

#include <string>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {};

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->getNext();
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
};

void LinkedList::insert(const DictionaryWord& value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

void LinkedList::remove(const std::string& value) {
    if (head == nullptr) {
        return;
    }

    if (head->getData() == value) {
        Node* temp = head;
        head = head->getNext();
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return;
    }

    Node* current = head;
    while (current->getNext() != nullptr) {
        if (current->getNext()->getData() == value) {
            Node* temp = current->getNext();
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

DictionaryWord* LinkedList::getValue(const std::string& key) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->getData() == key) {
            return &current->getData();
        }
        current = current->getNext();
    }
    return nullptr;
}

Node* LinkedList::getHeadNode() const {
    return head;
}
