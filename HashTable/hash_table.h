//
// Created by michael tsui on 2018/8/29.
//

#ifndef CALGO_HASH_TABLE_H
#define CALGO_HASH_TABLE_H

#include <cstdio>
#include <cmath>
#include <cstdlib>

namespace HashTable {
    struct ListNode;
    typedef struct ListNode *Position;
    struct HashTbl;
    typedef struct HashTbl *HashTable;
    typedef int ElementType;

    /* Export Interface */
    HashTable InitTable(int tableSize);
    void DestoryTable(HashTable h);
    Position Find(ElementType key, HashTable h);
    void Insert(ElementType key, HashTable h);
    ElementType Retrieve(Position p);

    /*
     * Internal func
     */
    int nextPrime(int n);
    bool isPrime(int n);

    /*
     * Internal MACRO
     */

    #define FATLN(msg) \
     fprintf(stderr, "error: %s:%d:%s ", __FILE__, __LINE__, __func__); \
     fprintf(stderr, "%s", msg); \
     exit(-1);

    struct ListNode {
        ElementType key;
        Position next;
    };

    typedef Position List;

    struct HashTbl {
        List *lists;
        int tableSize;
    };
}

#endif //CALGO_HASH_TABLE_H
