//
// Created by michael tsui on 2018/8/30.
//

#include "gtest/gtest.h"
#include "hash_table.h"

namespace HashTable {
    TEST(HashTable, InitTable) {
        HashTable t = InitTable(7);

        EXPECT_EQ(t->tableSize, 7);
        for (int i = 0; i < 7; i ++) {
            EXPECT_EQ(NULL, t->lists[0]->next);
        }
    }
}
