//
// Created by michael tsui on 2020-08-22.
//

#include <stdio.h>

namespace Analysis {

// 时间复杂度为 O(N)
int MaxSubsequenceSum4(const int A[], int N) {
    int thisSum = 0, maxSum = 0;
    for (int i = 0; i < N; i++) {

        thisSum += A[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        }

        if (thisSum < 0) {
            thisSum = 0;
        }
    }

    return maxSum;
}


}

