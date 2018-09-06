//
// Created by michael tsui on 2018/9/6.
//

#include "sample2.h"

namespace TestSample {

const char *MyString::CloneString(const char *a_c_string) {
    if (a_c_string == nullptr) return nullptr;

    const size_t len = strlen(a_c_string);
    auto *const clone = new char[len + 1];
    memcpy(clone, a_c_string, len + 1);

    return clone;
}

void MyString::Set(const char *a_c_string) {
    // http://www.cnblogs.com/jonnyyu/archive/2005/06/19/89766.html
    // const char * pt1  // const 修饰整个值
    // char * const pt2  // const 修饰指针
    // pt1 是一个常量字符串的指针，指针指向的值不可变，指针的地址可变
    // pt2 是一个指向字符串的常量指针，指针的地址不可变，指针指向的值可变
    const char *const temp = CloneString(a_c_string);
    delete []c_string_;
    c_string_ = temp;
};

}

