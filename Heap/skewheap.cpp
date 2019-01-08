//
// Created by michael tsui on 2019-01-09.
//

#include "skewheap.h"

namespace Heap {

SkewPriorityQueue Initialize(SkewPriorityQueue h) {
    return nullptr;
}

bool IsEmpty(SkewPriorityQueue H) {
    return H == nullptr;
}

void swapChild(SkewPriorityQueue heap) {
    SkewPriorityQueue tmp = nullptr;
    tmp = heap->Left;
    heap->Left = heap->Right;
    heap->Right = tmp;
}

SkewPriorityQueue merge1(SkewPriorityQueue H1, SkewPriorityQueue H2, int depth) {
    if (H1->Left == nullptr) {
        H1->Left = H2;
        return H1;
    }

    H1->Right = Merge(H1->Right, H2, depth + 1);
    if (depth != 0) {
        swapChild(H1);
    }

    return H1;
}

SkewPriorityQueue Merge(SkewPriorityQueue H1, SkewPriorityQueue H2, int depth) {
    if (H1 == nullptr) {
        return H2;
    }
    if (H2 == nullptr) {
        return H1;
    }

    if (H1->Element > H2->Element) {
        return merge1(H2, H1, depth);
    } else {
        return merge1(H1, H2, depth);
    }
}

SkewPriorityQueue Insert1(SkewPriorityQueue H, ElementType X) {
    SkewPriorityQueue singleNode = nullptr;

    singleNode = (SkewPriorityQueue) malloc(sizeof(struct SkewTreeNode));
    if (singleNode == nullptr) {
        FATLN("Out of the memory");
    }

    singleNode->Element = X;
    singleNode->Left = singleNode->Right = nullptr;

    H = Merge(H, singleNode);

    return H;
}

void Show(SkewPriorityQueue h, const std::string &prefix, bool isRight) {
    if (isRight) {
        printf("%s", (prefix + "├──").c_str());
    } else {
        printf("%s", (prefix + "└──").c_str());

    }

    if (IsEmpty(h)) {
        printf("{}\n");
        return;
    } else {
        printf("%d\n", h->Element);
    }

    if (IsEmpty(h->Left) && IsEmpty(h->Right)) {
        return;
    }

    Show(h->Right, prefix + (isRight ?  "│  " : "   "), true);
    Show(h->Left, prefix + (isRight ?  "│  " : "   "), false);
}

SkewPriorityQueue Destroy1(SkewPriorityQueue heap) {
    if (IsEmpty(heap))
        return nullptr;

    Destroy(heap->Right);
    Destroy(heap->Left);

    free(heap);

    return nullptr;
}

}
