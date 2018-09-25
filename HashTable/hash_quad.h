//
// Created by michael tsui on 2018/9/12.
//

#ifndef CALGO_HASH_QUAD_H
#define CALGO_HASH_QUAD_H

#include "utils.h"
#include <cstdio>
#include <cstdlib>

namespace HashTable {

typedef Index Position;

struct HashQuadEntry;
struct HashQuadTbl;
typedef struct HashQuadTbl* HashQuadTable;
typedef struct HashQuadEntry Cell;

/*
 *  Exported API
 */
HashQuadTable InitQuadTable(int tableSize);
void Insert(ElementType key, HashQuadTable t);
Position Find(ElementType key, HashQuadTable t);
void Delete(ElementType key, HashQuadTable t);
void DestroyTable(HashQuadTable t);
ElementType Retrieve(Position p, HashQuadTable t);
#define MinTableSize 17


enum KindOfEntry {
    Legitimate, Empty, Deleted
};

struct HashQuadEntry {
    ElementType elem;
    enum KindOfEntry info;
};

struct HashQuadTbl {
    Cell *theCells;
    int tableSize;
    int len;
};

}

#endif //CALGO_HASH_QUAD_H
