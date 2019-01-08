//
// Created by michael tsui on 2019-01-09.
//

#include "gtest/gtest.h"
#include "skewheap.h"

namespace Heap {

TEST(SkewHeap, Empty) {
    SkewPriorityQueue heap = Initialize();

    EXPECT_EQ(true, IsEmpty(heap));
}

TEST(SkewHeap, Merge) {
    SkewPriorityQueue h1 = Initialize(), h2 = Initialize(), h = Initialize();

    Insert(h1, 10);
    Insert(h2, 20);

    h = Merge(h1, h2);

//    Show(h);
    EXPECT_EQ(h->Element, 10);
}

TEST(SkewHeap, Insert) {
    SkewPriorityQueue h1 = Initialize();

    Insert(h1, 10);
    Insert(h1, 8);

//    Show(h1);
    EXPECT_EQ(8, h1->Element);
}

TEST(SkewHeap, Destroy) {
    SkewPriorityQueue h = Initialize();

    Insert(h, 30);
    Insert(h, 31);
    Insert(h, 29);
    Insert(h, 32);

    Destroy(h);

    EXPECT_EQ(h, nullptr);
}

}
