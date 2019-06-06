
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>
#include <stdio.h>

// 'b' is a shuffled array 'a' with two elements removed, find these elements
void find_removed_numbers(int *a, int *b, int n) {

    int xxor = 0;
    for(int i = 0; i < n - 2; i++)
        xxor ^= a[i] ^ b[i];

    xxor ^= a[n-2] ^ a[n-1];
    // now xxor = removed
    printf("xxor: %d\n", xxor);

    int x = 0, y = 0, bit = xxor & (-xxor); // LSB bit set
    // meaning that searched-for numbers differ in at least this bit

    for(int i = 0; i < n; i++) {
        if(bit & a[i]) {
            x ^= a[i];
        } else {
            y ^= a[i];
        }

        if(i >= n-2)
            continue;
        if(bit & b[i]) {
            x ^= b[i];
        } else {
            y ^= b[i];
        }
    }

    printf("missing: %d %d\n", x, y);
}

int main() {
 
     int a[] = {11,5,2,234,345,4,2,23,4,45,345,43,2,4,5};
     int b[] = {2,234,345,4,2,23,4,45,345,43,2,4,5};
 
     int n = sizeof(a)/sizeof(int);
     find_removed_numbers(a, b, n);
     
    return 1;
}
 
