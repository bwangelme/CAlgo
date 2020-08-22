//
// Created by michael tsui on 2020/8/22.
//

#include <gtest/gtest.h>
#include "max_subseq_sum.h"

namespace Analysis {

TEST(MaxSubseqSum3, ALL) {
    int array[] = {-2, 11, -4, 13, -5, -2};
    EXPECT_EQ(20, MaxSubsequenceSum3(array, sizeof(array) / sizeof(array[0])));

    int array1[] = {4, -3, 5, -2, -1, 2, 6, -2};
    EXPECT_EQ(11, MaxSubsequenceSum3(array1, sizeof(array1) / sizeof(array1[0])));
}

TEST(MAX3, ALL) {
    EXPECT_EQ(Max3(1, 2, 3), 3);
    EXPECT_EQ(Max3(-1, 0, 1), 1);
    EXPECT_EQ(Max3(0, 0, 0), 0);
    EXPECT_EQ(Max3(1, 1, 3), 3);
}

}
