//
// Created by mrr on 11/05/23.
//

#include "StarNode.h"
#include <iostream>
#include "StarNode.h"

StarNode::StarNode(int value1, int value2) {
    this->value1 = value1;
    this->value2 = value2;
    this->next = nullptr;
}

int StarNode::getNode(int index) const {
    if(index == 0) {
        return value1;
    } else if(index == 1) {
        return value2;
    } else {
        return -1; // or throw an exception
    }
}

StarNode* StarNode::getNext() const {
    return next;
}

void StarNode::setNext(StarNode* nextNode) {
    next = nextNode;
}

int StarNode::getNodeX() {
    if (this == nullptr) {
        return 100; // o cualquier otro valor predeterminado
    } else{
        return value1;
    }

}

int StarNode::getNodeY() {
    if (this == nullptr) {
        return 0; // o cualquier otro valor predeterminado
    } else{
        return value2;
    }

}