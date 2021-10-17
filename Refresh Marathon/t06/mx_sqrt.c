int mx_sqrt(int x);

int mx_sqrt(int x) {

    int i = 1;

    while (i <= x / i) {
        if((i * i) == x) {
            return i;
        }
        i++;
    }
    
    return 0;
}

