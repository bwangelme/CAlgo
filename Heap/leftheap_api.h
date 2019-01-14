//
// Created by michael tsui on 2019-01-10.
//

#include "helper.h"

namespace Heap {

/*
 * 左式堆接口
 *
 */
class LeftHeapInterfaceStruct;
typedef LeftHeapInterfaceStruct *LeftHeapInterface;
class LeftHeapInterfaceStruct {
    virtual LeftHeapInterface getLeft()=0;
    virtual LeftHeapInterface getRight()=0;
    virtual ElementType getElement()=0;
};

ElementType FindMin(LeftHeapInterface);

LeftHeapInterface Initialize();

bool IsEmpty(LeftHeapInterface);

LeftHeapInterface Merge(LeftHeapInterface, LeftHeapInterface);

#define Insert(H, X) (H = Insert1(H, ( X )))
#define DeleteMin(H) \
    FindMin(H);\
    H = DeleteMin1(H);


#define Destroy(H) (H = Destroy1(H))

LeftHeapInterface Insert1(LeftHeapInterface, ElementType);

LeftHeapInterface DeleteMin1(LeftHeapInterface H, ElementType X);

LeftHeapInterface Destroy1(LeftHeapInterface);

LeftHeapInterface DeleteMin1(LeftHeapInterface);

void
Show(LeftHeapInterface, const std::string &prefix = "", bool isRight = false);
}

