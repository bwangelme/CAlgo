//
// Created by michael tsui on 2019-01-05.
//
// 左式堆 Leftist Heap
//

#ifndef CALGO_LEFTHEAP_H
#define CALGO_LEFTHEAP_H

#include "helper.h"
#include "leftheap_api.h"
#include "iostream"

namespace Heap {

typedef struct TreeNode *LeftPriorityQueue;

class TreeNode : public LeftHeapInterfaceStruct {
public:
    ElementType Element;
    LeftPriorityQueue Left;
    LeftPriorityQueue Right;
    int npl;

    LeftHeapInterface getRight() override {
        return this->Right;
    }

    LeftHeapInterface getLeft() override {
        return this->Left;
    }

    ElementType getElement() override {
        return this->Element;
    }
};


}

#endif //CALGO_LEFTHEAP_H
