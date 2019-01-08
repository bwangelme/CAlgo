//
// Created by michael tsui on 2019-01-05.
//
// 左式堆 Leftist Heap
//

#ifndef CALGO_LEFTHEAP_H
#define CALGO_LEFTHEAP_H

#include "helper.h"
#include "iostream"

namespace Heap {

typedef struct TreeNode *LeftPriorityQueue;

LeftPriorityQueue Initialize(LeftPriorityQueue h = nullptr);

ElementType FindMin(LeftPriorityQueue H);

bool IsEmpty(LeftPriorityQueue H);

LeftPriorityQueue Merge(LeftPriorityQueue H1, LeftPriorityQueue H2);

#define Insert(H, X) (H = Insert1(H, ( X )))
#define DeleteMin(H) \
    FindMin(H);\
    H = DeleteMin1(H);


#define Destroy(H) (H = Destroy1(H))

LeftPriorityQueue Insert1(LeftPriorityQueue H, ElementType X);

LeftPriorityQueue DeleteMin1(LeftPriorityQueue H, ElementType X);

LeftPriorityQueue Destroy1(LeftPriorityQueue);

LeftPriorityQueue DeleteMin1(LeftPriorityQueue);

void
Show(LeftPriorityQueue, const std::string &prefix = "", bool isRight = false);

struct TreeNode {
    ElementType Element;
    LeftPriorityQueue Left;
    LeftPriorityQueue Right;
    int npl;
};

}

#endif //CALGO_LEFTHEAP_H
