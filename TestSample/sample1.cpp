//
// Created by michael tsui on 2018/9/3.
//

#include "sample1.h"

namespace TestSample {

bool IsPrime(int n) {
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

int Factorial(int n) {
    if (n <= 0) {
        return 1;
    }

    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int max(int a, int b) {
    return a;
}

}
