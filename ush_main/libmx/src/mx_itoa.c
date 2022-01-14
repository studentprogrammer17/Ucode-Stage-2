#include "../inc/libmx.h"

char *mx_itoa(int number) {
    bool is_neg = false;
    int i = 0;
    char *str = (char*)malloc(100);
    if(number == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (number == -2147483648){
        return "-2147483648";
    }

    if(number < 0) {
        is_neg = true;
        number = -number;
    }

    while(number != 0) {
        int dig = number % 10;

        if(dig > 9) {
           str[i++] = (dig - 10) + 'a';
        }

        else {
           str[i++] =  dig + '0';
        }

        number /= 10;
    }

    if(is_neg) {
        str[i++] = '-';
    }

    str[i] = '\0';

    mx_str_reverse(str);

    return str;
}

