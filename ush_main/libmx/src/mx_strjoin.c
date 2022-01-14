#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if(s1 == NULL && s2 == NULL) {
        return NULL;
    }

    else if(s1 == NULL) {
        return mx_strdup(s2);
    }

    else if(s2 == NULL) {
        return mx_strdup(s1);
    }

    else {
        char *s3 = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        int j = 0;
        for(int i = 0; i < mx_strlen(s1) + mx_strlen(s2); i++) {
            if(i >= mx_strlen(s1)) {
                s3[i] = s2[j];
                j++;
            }
            else {
                s3[i] = s1[i];
            }
        }
        s3[mx_strlen(s1) + mx_strlen(s2)] = '\0';
        return s3;
    }

}

