//
// Created by michael tsui on 2018/9/12.
//

#include "hash_quad.h"
#include <gtest/gtest.h>

namespace HashTable{

TEST(HashQuadTable, Init) {
    int tableSize = 7;
    HashQuadTable t = InitQuadTable(7);

    EXPECT_EQ(t->tableSize, tableSize);
    for (int i = 0; i < tableSize; i++) {
        EXPECT_EQ(Empty, t->theCells[i].info);
    }
}

TEST(HashQuadTable, InitFailed) {
    HashQuadTable t = InitQuadTable(1);
    EXPECT_EQ(nullptr, t);
}

TEST(HashQuadTable, Insert) {
    HashQuadTable t = InitQuadTable(8);
    Position p;
    ElementType key = 7;

    Insert(key, t);
    p = Find(key, t);

    EXPECT_EQ(key, t->theCells[p].elem);
    EXPECT_EQ(Legitimate, t->theCells[p].info);
}

TEST(HashQuadTable, Find) {
    HashQuadTable t = InitQuadTable(8);
    Position p;
    ElementType key = 7;

    p = Find(key, t);
    EXPECT_EQ(t->theCells[p].info, Empty);
}

}
