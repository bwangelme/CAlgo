//
// Created by michael tsui on 2018/8/30.
//

#include "hash_table.h"

namespace HashTable {
    int hash(ElementType x, int tableSize) {
        return x % tableSize;
    }

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

        t->lists = (List *)malloc(t->tableSize * sizeof(struct ListNode));
        for (int i = 0; i < tableSize; i++) {
            t->lists[i] = (List)malloc(sizeof(struct ListNode));
            if (t->lists[i] == nullptr) {
                FATLN("malloc failed");
            }
            t->lists[i]->next = nullptr;
            t->lists[i]->key = 0;
        }

        return t;
    }

    Position Find (HashTable t, ElementType key) {
        if (t == nullptr) {
            return nullptr;
        }

        Position p;
        List l;

        l = t->lists[hash(key, t->tableSize)];
        p = l->next;

        while (p != nullptr && key != p->key) {
            p = p->next;
        }

        return p;
    }

    void Insert(HashTable t, ElementType key) {
        if (t == nullptr) {
            return;
        }

        List l;
        Position p, newCell;

        p = Find(t, key);

        if (p == nullptr) {
            newCell = (Position)malloc(sizeof(struct ListNode));
            if (newCell == nullptr) {
                FATLN("malloc failed");
            }

            l = t->lists[hash(key, t->tableSize)];

            newCell->next = l->next;
            newCell->key = key;
            l->next = newCell;
        }
    }
}
