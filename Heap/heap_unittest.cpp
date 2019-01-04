#include "heap.h"
#include "gtest/gtest.h"

TEST(HeapStruct, Initialize) {
    int maxElements = 20;
    auto heap = Initialize(maxElements);

    EXPECT_EQ(heap->capacity, maxElements);
    EXPECT_EQ(heap->elements[0], INT_MIN);
    Destroy(heap);
}


TEST(HeapStruct, InitFailed) {
    auto heap = Initialize(0);

    EXPECT_EQ(heap, nullptr);
    Destroy(heap);
}


TEST(HeapStruct, IsFull) {
    auto heap = Initialize(1);

    EXPECT_EQ(false, IsFull(heap));
    Insert(heap, 10);
    EXPECT_EQ(true, IsFull(heap));
    Destroy(heap);
}

TEST(HeapStruct, Insert) {
    auto heap = Initialize(3);

    Insert(heap, 10);
    Insert(heap, 7);
    Insert(heap, 4);

    EXPECT_EQ(4, heap->elements[1]);
    EXPECT_EQ(10, heap->elements[2]);
    EXPECT_EQ(7, heap->elements[3]);

    Destroy(heap);
}

TEST(HeapStruct, Destroy) {
    auto heap = Initialize(1);

    EXPECT_NE(nullptr, heap);
    Destroy(heap);
    EXPECT_EQ(nullptr, heap);
}

TEST(HeapStruct, Show) {
    auto heap = Initialize(5);

    Insert(heap, 10);
    Insert(heap, 7);
    Insert(heap, 2);
    Insert(heap, 8);
    Insert(heap, 4);

    Show(heap, "", 1, false);
    Destroy(heap);
}

TEST(HeapStruct, DeleteMin) {
    auto heap = Initialize(5);

    Insert(heap, 10);
    Insert(heap, 7);
    Insert(heap, 2);
    Insert(heap, 8);
    Insert(heap, 4);

    DeleteMin(heap);

    ElementType minElement = heap->elements[1], lastElement = heap->elements[heap->size];

    EXPECT_EQ(minElement, 4);
    EXPECT_EQ(lastElement, 10);
}
