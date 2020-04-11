//
// test.cpp

#include <iostream>
#include <cstdio>
#include <string>
#include "nanojson.h"

static int main_ret = 0;
static int test_cnt = 0;
static int test_pas = 0;

#define EXPECT_EQ_BASE(equaltiy, expect, actual, format) \
    do { \
        test_cnt++; \
        if (equality) { \
            test_pas++; \
        else { \
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual); \
            main_ret = 1; \
        } \
    } while (0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

static void testParseNull {
    NanoValue lv;
    lv.type = NANO_TRUE;
    
}
