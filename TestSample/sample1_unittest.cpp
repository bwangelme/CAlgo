//
// Created by michael tsui on 2018/9/3.
//

/*
 * ToRead: https://github.com/google/googletest/blob/master/googletest/docs/primer.md#beware-of-the-nomenclature
 */

#include <gtest/gtest.h>
#include "sample1.h"

/*
 *   使用 TEST 宏来定义测试，TEST 有两个参数，test case 名称和 test 名称
 *
 *   在 GoogleTest 中，test 被组织成 test case，
 * 应该将逻辑上一组的 test 放置在同一组 test case 中
 *
 *   test case 名字和 test 名字都应该是有效的 C++ 标识符，而且不应该在名字中间使用下划线
 *
 *   GoogleTest 可以保证每个 test 只运行一次，但是它不能保证 test 是按顺序运行的，
 * 所以在写 test 代码的时候应该保证 test 的正确性不依赖于它们的运行顺序
 */

namespace TestSample {

    // EXPECT_EQ 等价于 EXPECT_TRUE(1 == Factorial(-5))
    // EXPECT_TRUE 接收布尔表达式而且它更通用
    TEST(FactorialTest, Negative) {
        EXPECT_EQ(1, Factorial(-5));
        EXPECT_EQ(1, Factorial(-2));
        EXPECT_LT(0, Factorial(-10));
    }

    TEST(FactorialTest, Zero) {
        EXPECT_EQ(1, Factorial(0));
    }

    TEST(FactorialTEst, Positive) {
        EXPECT_EQ(1, Factorial(1));
        EXPECT_EQ(2, Factorial(2));
        EXPECT_EQ(24, Factorial(4));
        EXPECT_EQ(362880, Factorial(9));
    }

    //TODO: 测试int溢出的情况
}

