//
// Created by michael tsui on 2018/8/30.
//

#include "hash_table.h"

namespace HashTable {
    HashTable InitTable(int tableSize) {
        HashTable t = (HashTable)malloc(sizeof(struct HashTbl));
        if (t == NULL) {
            FATLN("malloc failed");
        }
        return t;
    }
}
