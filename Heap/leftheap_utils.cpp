//
// Created by michael tsui on 2019-01-10.
//

#include "leftheap_api.h"


LeftHeapInterface Initialize() {
    return nullptr;
}

ElementType FindMin(LeftHeapInterface h) {
    if (IsEmpty(h)) {
        Error("heap h is empty");
        return -1;
    }

    return h->Element;
}

bool IsEmpty(LeftHeapInterface heap) {
    return heap == nullptr;
}

LeftHeapInterface Destroy1(LeftHeapInterface heap) {
    if (IsEmpty(heap))
        return nullptr;

    Destroy(heap->getLeft());
    Destroy(heap->getRight());

    free(heap);

    return nullptr;
}
