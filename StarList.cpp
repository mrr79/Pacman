//
// Created by mrr on 11/05/23.
//
#include <iostream>
#include "StarList.h"
StarList::StarList() {
    this->head = nullptr;
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
    if (nodo_actual->getNodeX() != 100){
        nodo_actual = nodo_actual->getNext();
    }
    while (nodo_actual != nullptr) {
        std::cout << " --> "
                  << "(" << nodo_actual->getNodeX() << "," << nodo_actual->getNodeY() << ")";
        nodo_actual = nodo_actual->getNext();
    }
    std::cout << std::endl;
}

StarNode* StarList::getHead() const {
    if (this->head == nullptr) {
        return nullptr;
    } else {
        return this->head;
    }
}

int StarList::size() const {
    int count = 0;
    StarNode* nodo_actual = this->head;
    while (nodo_actual != nullptr) {
        count++;
        nodo_actual = nodo_actual->getNext();
    }
    std::cout << "ELEMENTOS EN LISTA " << count << std::endl;
    return count;

}


void StarList::removeHead() {
    if (this->head != nullptr) {
        StarNode* temp = this->head;
        this->head = this->head->getNext();
        delete temp;
    }
}

bool StarList::isEmpty() const {
    if (this->head == nullptr) {
        std::cout << "La lista está vacía" << std::endl;
        return true;
    } else {
        std::cout << "La lista no está vacía" << std::endl;
        return false;
    }
}
StarNode* StarList::getRandomNode() const {
    int count = size();
    if (count == 0) {
        return nullptr;
    }
    int random_index = rand() % count;

    StarNode* nodo_actual = this->head;
    int current_index = 0;
    while (current_index < random_index && nodo_actual->getNext() != nullptr) {
        nodo_actual = nodo_actual->getNext();
        current_index++;
    }
    std::cout << " --> "
              << "(" << nodo_actual->getNodeX() << "," << nodo_actual->getNodeY() << ")";
    return nodo_actual;
}

void StarList::clear() {
    while (head != nullptr) {
        StarNode* temp = head;
        head = head->getNext();
        delete temp;
    }
}