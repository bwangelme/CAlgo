//
// Created by michael tsui on 2019-01-03.
//

#ifndef CALGO_HELPER_H
#define CALGO_HELPER_H

#include <cstdlib>
#include <cstdio>

typedef int ElementType;

/*
 * Internal MACRO
 */
#define Error(msg) \
    fprintf(stderr, "error: %s:%d:%s ", __FILE__, __LINE__, __func__); \
    fprintf(stderr, "%s\n", msg);

#define FATLN(msg) \
    Error(msg) \
    exit(-1);

#endif //CALGO_HELPER_H
