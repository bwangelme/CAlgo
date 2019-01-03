//
// Created by michael tsui on 2018/9/12.
//

#include "hash_quad.h"
#include <gtest/gtest.h>

namespace HashTable{

TEST(HashQuadTable, Init) {
    int tableSize = 101;
    HashQuadTable t = InitQuadTable(tableSize);

    EXPECT_EQ(t->tableSize, tableSize);
    for (int i = 0; i < tableSize; i++) {
        EXPECT_EQ(Empty, t->theCells[i].info);
    }
}

TEST(HashQuadTable, InitFailed) {
    HashQuadTable t = InitQuadTable(16);
    EXPECT_EQ(nullptr, t);
}

TEST(HashQuadTable, Insert) {
    HashQuadTable t = InitQuadTable(101);
    Position p;
    ElementType key = 7;

    Insert(key, t);
    p = Find(key, t);

    EXPECT_EQ(key, t->theCells[p].elem);
    EXPECT_EQ(Legitimate, t->theCells[p].info);
}

TEST(HashQuadTable, Find) {
    HashQuadTable t = InitQuadTable(101);
    Position p;
    ElementType key = 7;

    p = Find(key, t);
    EXPECT_EQ(t->theCells[p].info, Empty);
}


TEST(HashQuadTable, Delete) {
    HashQuadTable t = InitQuadTable(101);
    Position p;
    ElementType key = 7;

    Insert(key, t);
    Delete(key, t);

    p = Find(key, t);

    EXPECT_EQ(t->theCells[p].info, Empty);
}


TEST(HashQuadTable, Retrieve) {
    HashQuadTable t = InitQuadTable(101);
    Position p;
    ElementType key = 7;

    Insert(key, t);
    p = Find(key, t);
    EXPECT_EQ(key, Retrieve(p, t));
}


TEST(HashQuadTable, DestroyTable) {
    HashQuadTable t = InitQuadTable(101);
    DestroyTable(t);
}

TEST(HashQuadTable, Rehash) {
    HashQuadTable t = InitQuadTable(MinTableSize);

    for (int i = 0; i < MinTableSize + 10; i++) {
        Insert(i, t);
    }

    EXPECT_EQ(t->len, MinTableSize + 10);
    EXPECT_EQ(Find(MinTableSize, t), MinTableSize);

    DestroyTable(t);
}

}
