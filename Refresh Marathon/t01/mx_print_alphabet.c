#include <unistd.h>

void mx_printchar(char c);

void mx_print_alphabet(void) {
    
    int j = 98;
    for(int i = 65; i <= 90; i++) {

        mx_printchar(i);

        for(; j <= 122; j++) {
            mx_printchar(j);
            i++;
            j++;
            break;
        }
        j++;
    }

    write(1,"\n",1);
}

