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

static void testParseNull() {
    NanoValue nv;
    nv.type = NANO_FALSE;
    EXPECT_EQ_INT(NANO_PARSE_OK, nanoParse(&nv, std::string("null"));
    EXPECT_EQ_INT(NANO_NULL, nanoGetType(&nv));
}

static void testParseExpectValue() {
	NanoValue nv;
	nv.type = NANO_FALSE;

    EXPECT_EQ_INT(NANO_PARSE_EXPECT_VALUE, nanoParse(&nv, ""));
    EXPECT_EQ_INT(NANO_NULL, nanoGetType(&nv));

    nv.type = NANO_FALSE;
    EXPECT_EQ_INT(NANO_PARSE_EXPECT_VALUE, nanoParse(&nv, " "));
    EXPECT_EQ_INT(NANO_NULL, nanoGetType(&nv));
}

static void testParseInvalidValue() {
    NanoValue nv;
    nv.type = NANO_FALSE;
    EXPECT_EQ_INT(NANO_PARSE_INVALID_VALUE, nanoParse(&v, "nul"));
    EXPECT_EQ_INT(NANO_NULL, nanoGetType(&nv));

    nv.type = NANO_FALSE;
    EXPECT_EQ_INT(NANO_PARSE_INVALID_VALUE, nanoParse(&v, "?"));
    EXPECT_EQ_INT(NANO_NULL, nanoGetType(&nv));
}

static void testParseRootNotSingular() {
	NanoValue nv;
    nv.type = NANO_FALSE;
    EXPECT_EQ_INT(NANO_PARSE_ROOT_NOT_SINGULAR, nanoParse(&nv, "null x"));
    EXPECT_EQ_INT(NANO_NULL, nanoGetType(&nv));
}

static void testParse() {
	testParseNull();
	testParseExpectValue();
	testParseInvalidValue();
	testParseRootNotSingular();
}

int main() {
	testParse();
	printf("%d/%d (%3.2f%%) passed\n", test_pas, test_cnt, test_pas * 100.0 / test_cnt);

	return main_ret;
}
