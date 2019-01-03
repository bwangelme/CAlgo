//
// Created by michael tsui on 2019/1/2.
//

#include "heap_struct.h"

PriorityQueue Initialize(int maxElements) {
    if (maxElements < MIN_PQ_SIZE) {
        Error("maxElements too small");
        return nullptr;
    }

    auto heap = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    if (heap == nullptr) {
        FATLN("Out of the memory");
    }

    auto elements = (ElementType *)malloc(sizeof(ElementType) * (maxElements + 1));
    if (elements == nullptr) {
        FATLN("Out of the memory");
    }

    elements[0] = INT_MIN;
    heap->size = 0;
    heap->capacity = maxElements;
    heap->elements = elements;

    return heap;
}


bool IsFull(PriorityQueue h) {
    return h->size >= h->capacity;
}


void Insert(PriorityQueue h, ElementType x) {
    int i = 0;

    if (IsFull(h)) {
        Error("Heap is full");
        return;
    }

    for (i = ++h->size; h->elements[i/2] > x; i /= 2) {
        h->elements[i] = h->elements[i/2];
    }
    h->elements[i] = x;
}

void Destroy(PriorityQueue &h) {
    if (h == nullptr) {
        return;
    }

    free(h->elements);
    free(h);

    h = nullptr;
}
