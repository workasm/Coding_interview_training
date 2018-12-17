
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>
#include <stdio.h>

/** 25-26,83-84,85-86,89-90,93-94,95-96,103-104,107-108,109-110,113-114,117-118,119-120,123-124,133-134,149-150,151-152,153-154,155-156,157-158,159-160
*/

// bin_search_matrix(int i1, int i2, int i3, int i4, int x) {
// 
//     midx = a[i1 + i2]
// 
// }
// 
// min := 1;
//   max := N; {array size: var A : array [1..N] of integer}
//   repeat
//     mid := (min+max) div 2;
//     if x > A[mid] then
//       min := mid + 1;
//     else
//       max := mid - 1;
//   until (A[mid] = x) or (min > max);

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


void brute_force() {

    int c = 0;  // solution counter
    int n_fact = 120; // this is n!
    
    for(int x = 0; x <= n_fact*2; x++) {
        int y = (x == n_fact ? 1 : x*n_fact / (x-n_fact));
        if(y*n_fact == x*(y-n_fact))
            printf("%d: %d %d\n", ++c, x, y);
    }

    for(int y = 1; y < n_fact*2; y++) {
        int x = (y == n_fact ? 1 : y*n_fact / (y-n_fact));
        if(x*n_fact == y*(x-n_fact))
            printf("%d: %d %d\n", ++c, x, y);
    }
}

int main() {

    brute_force();

}

// int main() {
// 
//     int a[] = {11,5,2,234,345,4,2,23,4,45,345,43,2,4,5};
//     int b[] = {2,234,345,4,2,23,4,45,345,43,2,4,5};
// 
//     int n = sizeof(a)/sizeof(int);
// //     find_removed_numbers(a, b, n);
//     print2i5();
//     
//     
//     return 1;
// }
// 
