//
// Created by michael tsui on 2019-01-05.
//

#include "leftheap.h"
#include "gtest/gtest.h"

namespace Heap {

TEST(LeftPriorityQueue, Destroy) {
    LeftPriorityQueue h = Initialize();

    Insert(h, 30);
    Insert(h, 31);
    Insert(h, 29);
    Insert(h, 32);

    Destroy(h);

    EXPECT_EQ(h, nullptr);
}

TEST(LeftPriorityQueue, Insert) {
    LeftPriorityQueue h = Initialize();

    Insert(h, 20);
    Insert(h, 19);
    EXPECT_EQ(h->Element, 19);
    EXPECT_EQ(h->Left->Element, 20);
    EXPECT_EQ(h->Right, nullptr);

    Insert(h, 18);
    EXPECT_EQ(h->Element, 18);
    EXPECT_EQ(h->Left->Element, 19);
    EXPECT_EQ(h->Right, nullptr);

    Insert(h, 24);
    EXPECT_EQ(h->Right->Element, 24);

    EXPECT_EQ(h->Element, 18);
    EXPECT_EQ(h->Left->Element, 19);
    EXPECT_EQ(h->Right->Element, 24);
}

TEST(LeftHeapStruct, Merge) {
    LeftPriorityQueue
            h1 = Initialize(), h2 = Initialize(),
            h = nullptr, tmp = nullptr;

    Insert(h1, 21);
    Insert(h1, 10);
    Insert(h1, 14);
    Insert(h1, 23);
    Insert(h1, 3);
    tmp = Initialize();
    Insert(tmp, 17);
    Insert(tmp, 26);
    Insert(tmp, 8);
    Merge(h1, tmp);
//    Show(h1);

    Insert(h2, 12);
    Insert(h2, 18);
    Insert(h2, 24);
    Insert(h2, 33);
    Insert(h2, 6);
    tmp = Initialize();
    Insert(tmp, 7);
    Insert(tmp, 37);
    Insert(tmp, 18);
    Merge(h2, tmp);
//    Show(h2);

    h = Merge(h1, h2);
//    Show(h);

    EXPECT_EQ(h->Element, 3);
    EXPECT_EQ(h->Left->Element, 6);
    EXPECT_EQ(h->Right->Element, 10);
    EXPECT_EQ(h->Left->npl, 2);
    EXPECT_EQ(h->Right->npl, 1);

    Destroy(h);
}

TEST(LeftPriorityQueue, Show) {
    auto heap = Initialize();

    Insert(heap, 10);
    Insert(heap, 7);
    Insert(heap, 2);
    Insert(heap, 8);
    Insert(heap, 4);

    Show(heap);
    Destroy(heap);
}

TEST(LeftPriorityQueue, FindMin) {
    auto heap = Initialize();

    EXPECT_EQ(FindMin(heap), -1);
    Insert(heap, 10);
    Insert(heap, 7);
    Insert(heap, 2);
    Insert(heap, 8);
    Insert(heap, 4);

    EXPECT_EQ(FindMin(heap), 2);
    Destroy(heap);
}

TEST(LeftPriorityQueue, DeleteMin) {
    auto heap = Initialize();

    Insert(heap, 10);
    Insert(heap, 7);
    Insert(heap, 2);
    Insert(heap, 8);
    Insert(heap, 4);

    // 由于 DeleteMin 是宏实现的，所以只能通过这样的方式调用，无法当做函数的参数
    ElementType minElem = DeleteMin(heap);
    EXPECT_EQ(minElem, 2);
    Destroy(heap);
}

}
