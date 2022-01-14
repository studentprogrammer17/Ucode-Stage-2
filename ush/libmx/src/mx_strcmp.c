#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {

    for(; *s1; s1++, s2++) {

        if (*s1 != *s2) {
            break;
        }
    }

    return *s1 - *s2;
}

