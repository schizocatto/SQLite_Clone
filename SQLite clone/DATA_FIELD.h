//
//  DATA_FIELD.h
//  SQLite clone
//
//  Created by Nhat Minh on 24/05/2023.
//

#ifndef DATA_FIELD_h
#define DATA_FIELD_h
#define __USE_C99_MATH
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>


typedef struct {
    uint32_t id;
    char USERNAME[32];
    char EMAIL[255];
} Row;
//???
bool uint32_Input_Checker(const char* str);


#endif /* DATA_FIELD_h */
