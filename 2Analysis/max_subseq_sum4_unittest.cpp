//
// Created by michael tsui on 2020/8/22.
//

#include <gtest/gtest.h>
#include "max_subseq_sum.h"

namespace Analysis {

TEST(MaxSubseqSum4, ALL) {
    int array[] = {-2, 11, -4, 13, -5, -2};
    EXPECT_EQ(20, MaxSubsequenceSum4(array, sizeof(array) / sizeof(array[0])));

    int array1[] = {4, -3, 5, -2, -1, 2, 6, -2};
    EXPECT_EQ(11, MaxSubsequenceSum4(array1, sizeof(array1) / sizeof(array1[0])));
}

}
