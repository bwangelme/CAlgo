//
// Created by michael tsui on 2018/9/12.
//

#ifndef CALGO_UTILS_H
#define CALGO_UTILS_H

#include <cmath>
#include "helper.h"

namespace HashTable {

typedef unsigned int Index;

int nextPrime(int n);
bool isPrime(int n);
Index hash(ElementType x, int tableSize);
}


#endif //CALGO_UTILS_H
