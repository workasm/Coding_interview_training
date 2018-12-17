
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

void generate_subset_sums(int *a, int sz, int N, int S) {
    std::vector< int > sums(N + 1, 0);
    std::vector< std::vector< int > > nparts(N + 1);
    sums[0] = 1;
    nparts[0].push_back(0);
    for(int i = 0; i < sz; i++)
    for(int s = N; s >= 1; s--) {
        if(s < a[i] || sums[s - a[i]] == 0)
            continue;
        sums[s] = 1;
        std::vector< int >& np = nparts[s - a[i]];
        for(int j = 0; j < np.size(); j++) {
            if(np[j] + 1 <= S) // do not count wrong sums
                nparts[s].push_back(np[j] + 1);
        }
    }
    for(int s = 1; s <= N; s++) {
        printf("sums[%d] = %d [", s, sums[s]);
        for(int j = 0; j < nparts[s].size(); j++) {
            printf("%d ", nparts[s][j]);
        }
        printf("]\n");
    }
}


int main() {
   int a[] = {1,2,3,4,5,7};
   int sz = sizeof(a)/sizeof(int);
   generate_subset_sums(a, sz, 10, 3);
   return 1;
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
