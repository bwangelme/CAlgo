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
}
