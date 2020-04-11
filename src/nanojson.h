//
// nanojson.h

#ifndef NANOJSON_H__
#define NANOJSON_H__

typedef enum {
    NANO_NULL,
    NANO_FALSE,
    NANO_TRUE,
    NANO_NUMBER,
    NANO_STRING,
    NANO_ARRAY,
    NANO_OBJECT
} LeptType;

typedef struct { 
    LeptType type;
} LeptValue;

enum {
    NANO_PARSE_OK = 0,
    NANO_PARSE_EXPECT_VALUE,
    NANO_PARSE_INVALID_VALUE,
    NANO_PARSE_ROOT_NOT_SINGULAR
};

int nanoParse(LeptValue *plv, const std::string json);

LeptType nanoGetType(const LeptValue *plv);


#endif //NANOJSON_H__
