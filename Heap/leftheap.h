//
// Created by michael tsui on 2019-01-05.
//
// 左式堆 Leftist Heap
//

#ifndef CALGO_LEFTHEAP_H
#define CALGO_LEFTHEAP_H

#include "helper.h"

namespace Heap {

typedef struct TreeNode *LeftPriorityQueue;

struct TreeNode {
    ElementType Element;
    LeftPriorityQueue Left;
    LeftPriorityQueue Right;
    int npl;
};

}

#endif //CALGO_LEFTHEAP_H
