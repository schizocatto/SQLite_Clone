//
//  DATA_FIELD.c
//  SQLite clone
//
//  Created by Nhat Minh on 24/05/2023.
//

#include "DATA_FIELD.h"

bool uint32_Input_Checker(const char* str) {
    while (*str) {
        if (isdigit(*str++) == 0) return false;
    }
    return true;
}
