//
// Created by michael tsui on 2019-01-03.
//

#ifndef CALGO_HEAP_STRUCT_H
#define CALGO_HEAP_STRUCT_H

#include <climits>
#include "helper.h"

#define MIN_PQ_SIZE 1

typedef int ElementType;
typedef struct HeapStruct *PriorityQueue;

struct HeapStruct {
    int capacity;
    int size;
    ElementType *elements;
};

PriorityQueue Initialize(int maxElements);
bool IsFull(PriorityQueue h);
void Insert(PriorityQueue h, ElementType x);
void Destroy(PriorityQueue &h);

#endif //CALGO_HEAP_STRUCT_H
