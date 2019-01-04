//
// Created by michael tsui on 2019-01-03.
//

#ifndef CALGO_HEAP_STRUCT_H
#define CALGO_HEAP_STRUCT_H

#include <string>
#include <climits>
#include "helper.h"

#define MIN_PQ_SIZE 1

typedef int ElementType;
typedef struct HeapStruct *PriorityQueue;

/*
 *   根据二叉树的特性，如果某个节点在数组中的索引为i，
 * 那么它的左节点为2*i，右节点为2*i + 1，父节点为 i / 2
 *
 * 二叉堆是一棵完全二叉树
 * 堆序性: 在最小二叉堆中，每个节点都小于其子节点
 */
struct HeapStruct {
    int capacity;
    int size;
    ElementType *elements;
};

PriorityQueue Initialize(int maxElements);
bool IsFull(PriorityQueue h);
bool IsEmpty(PriorityQueue h);
void Insert(PriorityQueue h, ElementType x);
void Destroy(PriorityQueue &h);
ElementType DeleteMin(PriorityQueue h);
void Show(PriorityQueue h, const std::string &prefix = "", int node_index = 1, bool isLeft = false);

#endif //CALGO_HEAP_STRUCT_H
