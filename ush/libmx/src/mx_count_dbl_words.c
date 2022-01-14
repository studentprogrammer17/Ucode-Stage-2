#include "../inc/libmx.h"

int mx_count_dbl_words(const char *str, char first, char second) {
    int count = 0;
    int len;

    if (str == NULL)
        return -1;
    len = mx_strlen(str);
    for (int i = 0; i < len; i++) {
        if ((str[i] == first || str[i] == second) && (str[i+1] != '\0' && str[i+1] != first && str[i+1] != second)) {
            count++;
        }
    }
    if (str[0] != first && str[0] != second)
        count++;
    return count;
}

