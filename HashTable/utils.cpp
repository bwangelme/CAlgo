//
// Created by michael tsui on 2018/9/4.
//

#include "utils.h"

namespace HashTable {
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

Index hash(ElementType x, int tableSize) {
    if (x < 0) {
        x = -x;
    }

    return Index (x % tableSize);
}
}
