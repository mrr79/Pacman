//
// Created by mrr on 12/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_STARLIST_H
#define PROYECTO_2_DATOS_LL_STARLIST_H

#include "StarNode.h"

class StarList {
public:
    StarList();
    //~StarList();
    void append(StarNode* new_node);
    bool remove(int index);
    int size() const;
    StarNode* getHead() const;
    void printList() const;
    void removeHead();
    bool isEmpty() const;
private:
    StarNode* head;
    int listSize;
};


#endif //PROYECTO_2_DATOS_LL_STARLIST_H
