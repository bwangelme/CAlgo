//
// Created by michael tsui on 2019-01-15.
//

#include "leftheap_api.h"

ElementType Heap_getElement(void *heap) {
    Heap *self = (Heap *)heap;
    return self->element;
}

HeapType* Init(ElementType element) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->type->getElement = Heap_getElement;

    return (HeapType *)heap;
}


