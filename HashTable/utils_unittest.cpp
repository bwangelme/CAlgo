//
// Created by michael tsui on 2018/9/10.
//

#include <gtest/gtest.h>
#include "hash_table.h"


namespace HashTable {

TEST(isPrimeTest, Negative) {
    EXPECT_FALSE(isPrime(-1));
    EXPECT_FALSE(isPrime(-2));
    EXPECT_FALSE(isPrime(INT_MIN));
}

TEST(isPrimeTest, Trivial) {
    EXPECT_FALSE(isPrime(0));
    EXPECT_FALSE(isPrime(1));
    EXPECT_TRUE(isPrime(2));
    EXPECT_TRUE(isPrime(3));
}

TEST(isPrimeTest, Positive) {
    EXPECT_FALSE(isPrime(4));
    EXPECT_TRUE(isPrime(5));
    EXPECT_FALSE(isPrime(6));
    EXPECT_TRUE(isPrime(23));
}

TEST(nextPrimeTest, positive) {
    EXPECT_EQ(7, nextPrime(6));
    EXPECT_EQ(11, nextPrime(11));
}

TEST(nextPrimeTest, negative) {
    EXPECT_EQ(2, nextPrime(-1));
    EXPECT_EQ(2, nextPrime(0));
}
}
