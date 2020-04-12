//
// nanojson.cpp

#include "nanojson.h"
#include <cassert>
#include <string>

#define EXPECT(c, ch)  do { assert(*c->json == (ch)); c->json++; } while (0)

typedef struct {
	const char* json;
} NanoContext;

static void nanoParseWhitespace(NanoContext *pnc) {
	const char *pc = pnc->json;
	while (*pc == ' ' || *pc == '\t' || *pc == '\r') {
		pc++;
	}
	pnc->json = pc;
}

static int nanoParseNull(NanoContext *pnc, NanoValue *pnv) {
	EXPECT(pnc, 'n');
	if (pnc->json[0] != 'u' || pnc->json[1] != 'l' || pnc->json[2] != 'l') {
		return NANO_PARSE_INVALID_VALUE;
	}
	pnc->json += 3;
	pnv->type = NANO_NULL;

}


