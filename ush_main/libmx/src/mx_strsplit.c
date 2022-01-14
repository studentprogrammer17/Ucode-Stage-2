#include "../inc/libmx.h"

int mx_count_letters(const char *s, char c) {
    int letters = 0;

	for(int i = 0; s[i] != c && s[i]; i++) {
	    letters++;
    }

    return letters;
}

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }

    int word_size = 0;
    int i = 0;
    char **arr = NULL;
    arr = (char**)malloc((mx_count_words(s,c) + 1)  * sizeof(char *));
    while ((*s) && (*s != '\0')) {
        if (*s != c) {
            word_size = mx_count_letters(s, c);
            arr[i] = mx_strndup(s, word_size);
            s += word_size;
            i++;
            continue;
        }
        s++;
    }
    arr[i] = NULL;
    return arr;
}

