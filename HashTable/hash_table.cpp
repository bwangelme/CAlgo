//
// Created by michael tsui on 2018/8/30.
//

#include "hash_table.h"

namespace HashTable {
    HashTable InitTable(int tableSize) {
        auto t = (HashTable)malloc(sizeof(struct HashTbl));
        if (t == nullptr) {
            FATLN("malloc failed");
        }

        tableSize = nextPrime(tableSize);
        t->tableSize = tableSize;

        t->lists = (List *)malloc(sizeof(List) * tableSize);
        if (t->lists == nullptr) {
            FATLN("malloc failed")
        }

        for (int i = 0; i < tableSize; i++) {
            auto list = (List)malloc(sizeof(struct ListNode));
            if (list == nullptr) {
                FATLN("malloc failed")
            }
            t->lists[i] = list;
            t->lists[i]->next = nullptr;
            t->lists[i]->key = 0;
        }

        return t;
    }
}
