//
// Created by michael tsui on 2018/9/12.
//

#ifndef CALGO_UTILS_H
#define CALGO_UTILS_H

#include <cmath>

namespace HashTable {

typedef int ElementType;
typedef unsigned int Index;

/*
 * Internal func
 */
int nextPrime(int n);
bool isPrime(int n);
Index hash(ElementType x, int tableSize);

/*
 * Internal MACRO
 */
#define Error(msg) \
    fprintf(stderr, "error: %s:%d:%s ", __FILE__, __LINE__, __func__); \
    fprintf(stderr, "%s\n", msg);

#define FATLN(msg) \
    Error(msg) \
    exit(-1);
}


#endif //CALGO_UTILS_H
