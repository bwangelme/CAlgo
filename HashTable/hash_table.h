//
// Created by michael tsui on 2018/8/29.
//

#ifndef CALGO_HASH_TABLE_H
#define CALGO_HASH_TABLE_H

#include <cstdio>

namespace HashTable {
    struct ListNode;
    typedef struct ListNode *Position;
    struct HashTbl;
    typedef struct HashTbl *HashTable;
    typedef int ElementType;

    HashTable InitTable(int tableSize);
    void DestoryTable(HashTable h);
    Position Find(ElementType key, HashTable h);
    void Insert(ElementType key, HashTable h);
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
