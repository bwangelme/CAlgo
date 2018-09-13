//
// Created by michael tsui on 2018/8/29.
//

#ifndef CALGO_HASH_TABLE_H
#define CALGO_HASH_TABLE_H

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "utils.h"

namespace HashTable {

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

/* Export Interface */
HashTable InitTable(int tableSize);
void DestoryTable(HashTable &t);
void Insert(HashTable t, ElementType key);
Position Find(HashTable t, ElementType key);
ElementType Retrieve(Position p);

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
