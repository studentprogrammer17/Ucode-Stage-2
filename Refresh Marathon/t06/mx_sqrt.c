int mx_sqrt(int x);

int mx_sqrt(int x) {

    int i = 1;
    int result = 1;

    while (result <= x) {
      i++;
      result = i * i;
    }

    if((i - 1) * (i - 1) == x) {
        return i - 1;
    }
    
    else {
        return 0;
    }
}

