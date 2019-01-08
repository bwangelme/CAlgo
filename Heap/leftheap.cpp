//
// Created by michael tsui on 2019-01-05.
//

#include "leftheap.h"

namespace Heap {

LeftPriorityQueue Initialize(LeftPriorityQueue h) {
    return nullptr;
}

bool IsEmpty(LeftPriorityQueue H) {
    return H == nullptr;
}

LeftPriorityQueue Destroy1(LeftPriorityQueue H) {
    if (IsEmpty(H))
        return nullptr;

    Destroy(H->Right);
    Destroy(H->Left);

    free(H);

    return nullptr;
}

LeftPriorityQueue Insert1(LeftPriorityQueue H, ElementType X) {
    LeftPriorityQueue singleNode = nullptr;

    singleNode = (LeftPriorityQueue) malloc(sizeof(struct TreeNode));
    if (singleNode == nullptr) {
        FATLN("Out of the memory");
    }

    singleNode->Element = X;
    singleNode->npl = 0;
    singleNode->Left = singleNode->Right = nullptr;

    H = Merge(H, singleNode);

    return H;
}

void swapChild(LeftPriorityQueue H1) {
    LeftPriorityQueue tmp = nullptr;

    tmp = H1->Right;
    H1->Right = H1->Left;
    H1->Left = tmp;
}


LeftPriorityQueue merge1(LeftPriorityQueue H1, LeftPriorityQueue H2) {
    if (H1->Left == nullptr) {
        H1->Left = H2;
        return H1;
    }

    H1->Right = Merge(H1->Right, H2);
    if (H1->Left->npl < H1->Right->npl)
        swapChild(H1);

    H1->npl = H1->Right->npl + 1;

    return H1;
}

LeftPriorityQueue Merge(LeftPriorityQueue H1, LeftPriorityQueue H2) {
    if (H1 == nullptr)
        return H2;
    if (H2 == nullptr)
        return H1;

    if (H2->Element < H1->Element) {
        return merge1(H2, H1);
    } else {
        return merge1(H1, H2);
    }
}

void Show(LeftPriorityQueue h, const std::string &prefix, bool isRight) {
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

ElementType FindMin(LeftPriorityQueue h) {
    if (IsEmpty(h)) {
        Error("heap h is empty");
        return -1;
    }

    return h->Element;
}

LeftPriorityQueue DeleteMin1(LeftPriorityQueue heap) {
    LeftPriorityQueue leftHeap, rightHeap;

    if (IsEmpty(heap)) {
        Error("heap is empty");
        return nullptr;
    }

    leftHeap = heap->Left;
    rightHeap = heap->Right;
    free(heap);

    return Merge(leftHeap, rightHeap);
}

}
