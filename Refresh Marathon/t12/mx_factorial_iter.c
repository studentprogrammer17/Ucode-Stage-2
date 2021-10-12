int mx_factorial_iter(int n);

int mx_factorial_iter(int n) {
    
    unsigned int fact = 1;
    
    if (n > 12 || n < 0) {
        return 0;
    }
    
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
    
}

