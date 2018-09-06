//
// Created by michael tsui on 2018/9/6.
//

#include <gtest/gtest.h>
#include "sample2.h"

namespace TestSample {

TEST(MyString, DefaultConstructor) {
    MyString s;

    EXPECT_EQ(nullptr, s.c_string());
    EXPECT_EQ(0, s.Length());
}

const char kHelloString[] = "hello, world!";

TEST(MyString, ConstructFromCString) {
    MyString s(kHelloString);

    EXPECT_EQ(0, strcmp(kHelloString, s.c_string()));
    // S.Length() 统计出来的长度不包括字符串结尾的$
    // sizeof 统计的是字节数
    EXPECT_EQ(sizeof(kHelloString) / sizeof(kHelloString[0]) - 1, s.Length());
//    EXPECT_EQ(sizeof(kHelloString), sizeof(kHelloString[0]));
}

TEST(MyString, CopyStructor) {
    MyString s(kHelloString);

    MyString s1 = s;
    EXPECT_EQ(0, strcmp(s.c_string(), s1.c_string()));
    EXPECT_EQ(0, strcmp(kHelloString, s1.c_string()));
}


TEST(MyString, Set) {
    MyString s;

    s.Set(kHelloString);
    EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));

    s.Set(s.c_string());
    EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));

    s.Set(nullptr);
    EXPECT_EQ(nullptr, s.c_string());
}

}

