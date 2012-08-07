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
        /* removed check for if match found.  this didn't change the runtime */
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (v[high] == x)
        return high;
    else
        return -1; /* no match */
}
