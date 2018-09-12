//
// Created by michael tsui on 2018/9/12.
//

#ifndef CALGO_HASH_QUAD_H
#define CALGO_HASH_QUAD_H

#include "utils.h"

namespace HashTable {

typedef unsigned int Index;
typedef Index Position;

struct HashQuadEntry;
struct HashQuadTbl;
typedef struct HashQuadTbl* HashQuadTable;
typedef struct HashQuadEntry Cell;

/*
 *  Exported API
 */
HashQuadTable InitQuadTable(int tableSize);


enum KindOfEntry {
    Legitimate, Empty, Deleted
};

struct HashQuadEntry {
    ElementType elem;
    enum KindOfEntry entry;
};

struct HashQuadTbl {
    Cell *theCells;
    int tableSize;
};

}

#endif //CALGO_HASH_QUAD_H
