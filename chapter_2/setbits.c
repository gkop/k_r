int setbits(int x, int p, int n, int y) {
    int mask = 0;
    int i;

    // mask out the n right most bits
    for (i = 0; i < n; i++) {
        mask++;
        mask << 1;
    }

    // get those right most bits from y
    mask = y & mask

    // shift them over, if necessary
    if (p > n) 
        mask << p - n;
    else if (n > p)
        mask >> n - p;

    x & mask
}
