//
// Created by michael tsui on 2019-01-09.
//

#ifndef CALGO_SKEW_HEAP_H
#define CALGO_SKEW_HEAP_H

#include "iostream"
#include "helper.h"

namespace Heap {

typedef struct SkewTreeNode *SkewPriorityQueue;

// 由于会和 leftheap.h 中的同名函数冲突，所以这里加了一个 h 参数作为占位符，并无实际用途
// 因为函数重载只能根据参数，不能根据返回值
SkewPriorityQueue Initialize(SkewPriorityQueue h = nullptr);

ElementType FindMin(SkewPriorityQueue H);

bool IsEmpty(SkewPriorityQueue H);

SkewPriorityQueue Merge(SkewPriorityQueue H1, SkewPriorityQueue H2, int depth = 0);

#define Insert(H, X) (H = Insert1(H, ( X )))
#define DeleteMin(H) \
    FindMin(H);\
    H = DeleteMin1(H);


#define Destroy(H) (H = Destroy1(H))

SkewPriorityQueue Insert1(SkewPriorityQueue H, ElementType X);

SkewPriorityQueue DeleteMin1(SkewPriorityQueue H, ElementType X);

SkewPriorityQueue Destroy1(SkewPriorityQueue);

SkewPriorityQueue DeleteMin1(SkewPriorityQueue);

void
Show(SkewPriorityQueue, const std::string &prefix = "", bool isRight = false);

struct SkewTreeNode {
    ElementType Element;
    SkewPriorityQueue Left;
    SkewPriorityQueue Right;
};

}
#endif //CALGO_SKEW_HEAP_H
