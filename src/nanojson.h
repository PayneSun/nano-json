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
} NanoType;

typedef struct { 
    NanoType type;
} NanoValue;

enum {
    NANO_PARSE_OK = 0,
    NANO_PARSE_EXPECT_VALUE,
    NANO_PARSE_INVALID_VALUE,
    NANO_PARSE_ROOT_NOT_SINGULAR
};

int nanoParse(NanoValue *pnv, const std::string &json);

NanoType nanoGetType(const NanoValue *pnv);

#endif //NANOJSON_H__
