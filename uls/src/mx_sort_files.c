#include "uls.h"

void mx_swap_files(char file1, char file2) {
    char buf;

    buf = file1;
    file1 = file2;
    file2 = buf;
}

int mx_strcmp_unicode_1(const char *s1, const char *s2) {
    int i = 0;

    while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
        
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

void mx_sort_files(char **names) {
    names = NULL;
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if(dir->d_name[0] == '.') continue;
            for (unsigned int i = 0; (dir = readdir(d)) != NULL; i++) {
                if (mx_strcmp_unicode_1(&dir->d_name[i], &dir->d_name[i + 1]) > 0) {
                    mx_swap_files(dir->d_name[i], dir->d_name[i + 1]);
                    for (unsigned int j = i; j > 0; j--) {
                        if (mx_strcmp_unicode_1(&dir->d_name[j], &dir->d_name[j - 1]) < 0)
                            mx_swap_files(dir->d_name[j], dir->d_name[j - 1]);
                        else
                            break;
                    }
                }
            }
        }
        //mx_printchar('\n');
    }
}

