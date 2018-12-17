
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>

#include <math.h>
#include <stdio.h>

/** 25-26,83-84,85-86,89-90,93-94,95-96,103-104,107-108,109-110,113-114,117-118,119-120,123-124,133-134,149-150,151-152,153-154,155-156,157-158,159-160
*/

/** 
Given an array of non-negative integers A and a positive integer k, we want to:
Divide A into k or fewer partitions,
such that the maximum sum over all the partitions is minimized.
*/

// M[n,k] - optimal cost of a partition arrangement with blocks [0..n]
// and k paritions
// M[0,k] = a[0]
// M[n,0] = a[0] + .. + a[n]

// k painters to paint [s-e] board
int painter_problem(int *a, int n, int k) {

    std::vector< std::vector< int > > M(n);
    M[0] = std::vector< int >(k, a[0]);
    std::vector< int > sums(n);
    sums[0] = a[0];
    
    for(int i = 1; i < n; i++) {
        sums[i] = sums[i-1] + a[i];
        M[i] = std::vector< int >(k);
        M[i][0] = sums[i];
    }
    
    for(int i = 1; i < k; i++) { // go over all partitions
        for(int j = 1; j < n; j++) { // go over all elements
            // M[p][i-1] - elements up to 'p' using i-1 partitions
            int best = 0x1000000;
            // we can insert the next partition anywhere btw 0 and j
            for(int p = 0; p <= j; p++) {
                int pp = std::max(M[p][i-1], sums[j] - sums[p]);
                best = std::min(best, pp);
            }
            M[j][i] = best;
        }
    }
    return M[n-1][k-1];
}

// void find_kth_largest_sum(int *a, int *b, int n) {
// 
//     int i = 0, j = 0;
// 
//     for(i = 0; i < n; i++) {
//         for(j = 0; j < n; j++) {
//             
//         }
//     }
// }

int main() {
    int a[] = {10, 7, 1, 10, 10,  20, 1, 12};
    int n = sizeof(a) / sizeof(int);
    int k = 3;
    
    printf("mins: %d\n", painter_problem(a, n, k));
   
    return 1;
}




