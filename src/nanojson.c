#include "nanojson.h"
#include <assert.h>  /* assert() */
#include <stdlib.h>  /* NULL */

#define EXPECT(c, ch)       do { assert(*c->json == (ch)); c->json++; } while(0)

typedef struct {
    const char* json;
}nano_context;

static void nano_parse_whitespace(nano_context* c) {
    const char *p = c->json;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
        p++;
    c->json = p;
}

static int nano_parse_null(nano_context* c, nano_value* v) {
    EXPECT(c, 'n');
    if (c->json[0] != 'u' || c->json[1] != 'l' || c->json[2] != 'l')
        return nano_PARSE_INVALID_VALUE;
    c->json += 3;
    v->type = nano_NULL;
    return nano_PARSE_OK;
}

static int nano_parse_value(nano_context* c, nano_value* v) {
    switch (*c->json) {
        case 'n':  return nano_parse_null(c, v);
        case '\0': return nano_PARSE_EXPECT_VALUE;
        default:   return nano_PARSE_INVALID_VALUE;
    }
}

int nano_parse(nano_value* v, const char* json) {
    nano_context c;
    assert(v != NULL);
    c.json = json;
    v->type = nano_NULL;
    nano_parse_whitespace(&c);
    return nano_parse_value(&c, v);
}

nano_type nano_get_type(const nano_value* v) {
    assert(v != NULL);
    return v->type;
}
