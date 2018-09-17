//
// Created by michael tsui on 2018/9/12.
//

#include "hash_quad.h"


namespace HashTable {

HashQuadTable InitQuadTable(int tableSize) {
    if (tableSize < MinTableSize) {
        Error("table size too small");
        return nullptr;
    }

    HashQuadTable t = nullptr;

    t = (HashQuadTable)malloc(sizeof(struct HashQuadTbl));
    if (t == nullptr) {
        FATLN("malloc failed");
    }

    t->tableSize = nextPrime(tableSize);
    t->theCells = (Cell *)malloc(sizeof(HashQuadEntry) * t->tableSize);

    if (t->theCells == nullptr) {
        FATLN("malloc failed");
    }

    for (int i = 0; i < t->tableSize; i++) {
        t->theCells[i].info = Empty;
    }

    return t;
}

Position Find(ElementType key, HashQuadTable t) {
    Position currentPosition;
    int collisionCount = 0;

    currentPosition = hash(key, t->tableSize);
    // 寻找空的位置或者符合key的Entry
    // Note: 防止被删除过的元素被找到，要先检查是否为空，再检查key是否相等
    while(t->theCells[currentPosition].info != Empty &&
            t->theCells[currentPosition].elem != key) {
        // p = p + 2 * c -1
        currentPosition += 2 * ++collisionCount - 1;
        // p 大于 tableSize 后要拉回来
        if(currentPosition >= t->tableSize) {
            currentPosition -= t->tableSize;
        }
    }

    return currentPosition;
}

void Insert(ElementType key, HashQuadTable t) {
    Position p;

    p = Find(key, t);
    if (t->theCells[p].info != Legitimate) {
        t->theCells[p].info = Legitimate;
        t->theCells[p].elem = key;
    }
}

void Delete(ElementType key, HashQuadTable t) {
    Position p;

    p = Find(key, t);
    if (t->theCells[p].info != Empty) {
        t->theCells[p].info = Empty;
    }
}

void DestroyTable(HashQuadTable t) {
    free(t->theCells);
    free(t);
}

ElementType Retrieve(Position p, HashQuadTable t) {
    if (t->theCells[p].info == Legitimate) {
        return t->theCells[p].elem;
    }

    return ElementType(NULL);
}

}
