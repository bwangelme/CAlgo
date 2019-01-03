#include "heap_struct.h"
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
