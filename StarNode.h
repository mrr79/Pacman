//
// Created by mrr on 12/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_STARNODE_H
#define PROYECTO_2_DATOS_LL_STARNODE_H


class StarNode {
public:
    StarNode(int value1, int value2);
    int getNode(int index) const;
    StarNode* getNext() const;
    void setNext(StarNode* nextNode);
    int getNodeX();
    int getNodeY();
private:
    int value1;
    int value2;
    StarNode* next;
};


#endif //PROYECTO_2_DATOS_LL_STARNODE_H
