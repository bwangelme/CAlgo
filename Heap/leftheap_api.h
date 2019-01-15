//
// Created by michael tsui on 2019-01-14.
//

#ifndef CALGO_LEFTHEAP_API_H
#define CALGO_LEFTHEAP_API_H

#include "helper.h"

typedef struct HeapType {
    ElementType (* getElement)(void *);
}HeapType;

typedef struct Heap {
    ElementType element;
    HeapType *type;
} Heap;

HeapType* Init(ElementType element);

#endif //CALGO_LEFTHEAP_API_H
