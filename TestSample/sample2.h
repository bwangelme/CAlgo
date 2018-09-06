//
// Created by michael tsui on 2018/9/6.
//

#ifndef CALGO_SAMPLE2_H
#define CALGO_SAMPLE2_H

#include <cstring>

namespace TestSample {

class MyString {
private:
    const char *c_string_;

    const MyString &operator=(const MyString &rhs);

public:
    static const char *CloneString(const char *a_c_string);

    MyString() : c_string_(nullptr) {}

    //TODO: explicit 是什么意思
    explicit MyString(const char *a_c_string) : c_string_(nullptr) {
        Set(a_c_string);
    }

    MyString(const MyString &string) : c_string_(nullptr) {
        Set(string.c_string_);
    }

    ~MyString() { delete[] c_string_; }

    const char* c_string() const {
        return c_string_;
    }

    size_t Length() const {
        return c_string_ == nullptr ? 0 : strlen(c_string_);
    }

    void Set(const char *a_c_string);
};

}
#endif //CALGO_SAMPLE2_H
