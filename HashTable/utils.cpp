//
// Created by michael tsui on 2018/9/4.
//

#include "hash_table.h"
#include "gtest/gtest.h"

namespace HashTable {
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }

        for(int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

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

    int nextPrime(int n) {
        if (n <= 1) {
            return 2;
        }

        while(true) {
            if (isPrime(n)) {
                return n;
            } else {
                n++;
            }
        }
    }

    TEST(nextPrimeTest, positive) {
        EXPECT_EQ(7, nextPrime(6));
        EXPECT_EQ(11, nextPrime(11));
    }

    TEST(nextPrimeTest, negative) {
        EXPECT_EQ(2, nextPrime(-1));
        EXPECT_EQ(2, nextPrime(0));
    }

    void fatln(const char *message) {
        fprintf(stderr, message);
        exit(-1);
    }
}
