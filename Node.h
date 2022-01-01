//
// Created by Legion Y530 on 12/31/2021.
//

#ifndef NABIL_NODE_H
#define NABIL_NODE_H
#include <iostream>
#include "Dospem.h"
#include "Mhs.h"

class Node {
public:
    Node* next{};
    Node* child{};
    Dospem dospem;
    Mhs mhs;
    explicit Node(Dospem d) {
        this->dospem = d;
        this->next = NULL;
        this->child = NULL;
    }
    explicit Node(Mhs m) {
        this->mhs = m;
        this->next = NULL;
        this->child = NULL;
    }
};

#endif //NABIL_NODE_H
