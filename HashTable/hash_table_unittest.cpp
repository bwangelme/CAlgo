//
// Created by michael tsui on 2018/8/30.
//

#include "gtest/gtest.h"
#include "hash_table.h"

namespace HashTable {
    TEST(HashTable, InitTable) {
        HashTable t = InitTable(7);

        EXPECT_EQ(t->tableSize, 7);
        for (int i = 0; i < t->tableSize; i++) {
            EXPECT_EQ(nullptr, t->lists[0]->next);
            EXPECT_EQ(0, t->lists[0]->key);
        }
    }

    TEST(HashTable, InsertTable) {
        HashTable t = InitTable(11);
        ElementType key = 23;
        Position node;

        Insert(t, key);
        node = Find(t, key);
        EXPECT_NE(nullptr, node);
        EXPECT_EQ(key, node->key);
        EXPECT_EQ(nullptr, node->next);
    }
}
