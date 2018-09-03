//
// Created by michael tsui on 2018/9/3.
//

namespace TestSample {
    bool IsPrime(int n) {
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
}

