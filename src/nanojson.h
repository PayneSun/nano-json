#ifndef nanoJSON_H__
#define nanoJSON_H__

typedef enum { nano_NULL, nano_FALSE, nano_TRUE, nano_NUMBER, nano_STRING, nano_ARRAY, nano_OBJECT } nano_type;

typedef struct {
    nano_type type;
}nano_value;

enum {
    nano_PARSE_OK = 0,
    nano_PARSE_EXPECT_VALUE,
    nano_PARSE_INVALID_VALUE,
    nano_PARSE_ROOT_NOT_SINGULAR
};

int nano_parse(nano_value* v, const char* json);

nano_type nano_get_type(const nano_value* v);

#endif /* nanoJSON_H__ */
