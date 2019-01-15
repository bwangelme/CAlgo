//
// Created by michael tsui on 2019-01-15.
//

#include "leftheap_api.h"
#include "gtest/gtest.h"

TEST(LeftPriorityQueue, Init) {
    HeapType *heap = Init(20);

    EXPECT_EQ(heap->getElement(heap), 20);
}
