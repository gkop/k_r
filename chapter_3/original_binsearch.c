#include <stdio.h>

const int NUM_ELEMENTS = 2500000;

int main() {
    int space[NUM_ELEMENTS];
    int i;

    for (i = 0; i < NUM_ELEMENTS; i++) {
        space[i] = i;
    }

    for (i = 0; i < (NUM_ELEMENTS * 100); i++) {
        binsearch(-1, space, NUM_ELEMENTS);
    }
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* match found */
            return mid;
    }
    return -1; /* no match */
}
