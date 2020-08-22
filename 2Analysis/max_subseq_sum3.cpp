//
// 求解最大子序列和的问题
//

#include "algorithm"

namespace Analysis {

int Max3(int a, int b, int c) {
    if (std::max(a, b)) {
        return std::max(a, c);
    } else {
        return std::max(b, c);
    }
}

// static 限制 MaxSubSum 只能在本文件内访问
// 先求左边子序列的最大和，再求右边子序列的最大和。
// 然后再求包含中间元素的子序列的最大和，三者求最大值，就是当前序列的子序列最大和
static int MaxSubSum(const int A[], int Left, int Right) {
    int MaxLeftSum = 0, MaxRightSum = 0;
    if (Left == Right) {
        if (A[Left] > 0)
            return A[Left];
        else
            return 0;
    }

    int Center = (Left + Right) / 2;

    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center + 1, Right);

    int MaxBordedLeftSum = 0, BordedLeftSum = 0;
    for (int i = Center; i >= Left; i--) {
        BordedLeftSum += A[i];
        if (BordedLeftSum > MaxBordedLeftSum) {
            MaxBordedLeftSum = BordedLeftSum;
        }
    }

    int MaxBordedRightSum = 0, BordedRightSum = 0;
    for (int i = Center + 1; i <= Right; i++) {
        BordedRightSum += A[i];
        if (BordedRightSum > MaxBordedRightSum) {
            MaxBordedRightSum = BordedRightSum;
        }
    }

    int MaxCenterSum = MaxBordedLeftSum + MaxBordedRightSum;

    return Max3(MaxLeftSum, MaxRightSum, MaxCenterSum);
}

// 这种解法的时间复杂度是 O(N * LogN)
int MaxSubsequenceSum3(const int A[], int N) {
    return MaxSubSum(A, 0, N - 1);
}

}



