//
// Created by michael tsui on 2019/1/2.
//

#include "heap.h"

PriorityQueue Initialize(int maxElements) {
    if (maxElements < MIN_PQ_SIZE) {
        Error("maxElements too small");
        return nullptr;
    }

    auto heap = (PriorityQueue) malloc(sizeof(struct HeapStruct));
    if (heap == nullptr) {
        FATLN("Out of the memory");
    }

    auto elements = (ElementType *) malloc(
            sizeof(ElementType) * (maxElements + 1));
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

bool IsEmpty(PriorityQueue h) {
    return h->size == 0;
}


ElementType DeleteMin(PriorityQueue h) {
    if (IsEmpty(h)) {
        Error("Empty heap");
        return 0;
    }

    ElementType minElement = h->elements[1];
    ElementType lastElement = h->elements[h->size--];

    int hole_index, child;

    // 2 * hole_index <= h->size 这个条件保证了 hole_index 一定有子节点
    for (hole_index = 1; 2 * hole_index <= h->size; hole_index = child) {
        /*
         * 根据完全二叉树的特性，只有在树节点的个数为偶数个的情况下，
         * 才会出现最后一个节点的父节点只有一个子节点的情况
         *
         * 否则，除了叶子节点之外，其他所有节点都有两个子节点
         */
        child = 2 * hole_index;
        // child != h->size 表示 hole_index 有两个子节点
        if (child != h->size && h->elements[child] > h->elements[child + 1]) {
            child++;
        }

        if (h->elements[child] < lastElement) {
            h->elements[hole_index] = h->elements[child];
        } else {
            break;
        }
    }
    h->elements[hole_index] = lastElement;

    return minElement;
}


void Insert(PriorityQueue h, ElementType x) {
    int i = 0;

    if (IsFull(h)) {
        Error("Heap is full");
        return;
    }

    for (i = ++h->size; h->elements[i / 2] > x; i /= 2) {
        h->elements[i] = h->elements[i / 2];
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

void Show(PriorityQueue h, const std::string &prefix, int node_index, bool isLeft) {
    if (isLeft) {
        printf("%s", (prefix + "├──").c_str()) ;
    } else {
        printf("%s", (prefix + "└──").c_str());
    }

    printf("%d\n", h->elements[node_index]);
    int left_index = node_index * 2;
    int right_index = node_index*2 + 1;

    if (left_index <= h->size) {
        Show(h, prefix + (isLeft ? "│  " : "   "), left_index, true);
    }
    if (right_index <= h->size) {
        Show(h, prefix + (isLeft ? "│  " : "   "), right_index, false);
    }
}
