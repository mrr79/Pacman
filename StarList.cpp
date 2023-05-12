//
// Created by mrr on 11/05/23.
//
#include <iostream>
#include "StarList.h"
StarList::StarList() {
    this->head = nullptr;
}

StarList::~StarList() {
    StarNode* actual = this->head;
    StarNode* next;
    while (actual != nullptr) {
        next = actual->getNext();
        delete actual;
        actual = next;
    }
}

void StarList::append(StarNode* new_node) {
    if (this->head == nullptr) {
        this->head = new_node;
    } else {
        StarNode* nodo_actual = this->head;
        while (nodo_actual->getNext() != nullptr) {
            nodo_actual = nodo_actual->getNext();
        }
        nodo_actual->setNext(new_node);
    }
}

void StarList::printList() const {
    StarNode* nodo_actual = this->head;
    std::cout << "(" << nodo_actual->getNodeX() << "," << nodo_actual->getNodeY() << ")";
    nodo_actual = nodo_actual->getNext();
    while (nodo_actual != nullptr) {
        std::cout << " --> "
                  << "(" << nodo_actual->getNodeX() << "," << nodo_actual->getNodeY() << ")";
        nodo_actual = nodo_actual->getNext();
    }
    std::cout << std::endl;
}