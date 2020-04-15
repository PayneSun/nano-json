#ifndef nanoJSON_H__
#define nanoJSON_H__

typedef enum { NANO_NULL, NANO_FALSE, NANO_TRUE, NANO_NUMBER, NANO_STRING, NANO_ARRAY, NANO_OBJECT } nano_type;

typedef struct {
    nano_type type;
} nano_value;

enum {
    NANO_PARSE_OK = 0,
    NANO_PARSE_EXPECT_VALUE,
    NANO_PARSE_INVALID_VALUE,
    NANO_PARSE_ROOT_NOT_SINGULAR
};

int nano_parse(nano_value* v, const char* json);

nano_type nano_get_type(const nano_value* v);

#endif /* nanoJSON_H__ */
