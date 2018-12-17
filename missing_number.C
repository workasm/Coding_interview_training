
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>

int main() {
    int a[] = {2,1,3,4,8,6,7,8,9,10};
    int N = 10;
    int sum = 0, sum_sq = 0;
    for(int i = 0; i < N; i++) {
        sum += a[i];
        sum_sq += a[i]*a[i];
    }
    int true_sum = N*(N+1)/2,
        true_sum_sq = N*(N+1)*(2*N+1)/6;
    int X = true_sum - sum,
        Y = true_sum_sq - sum_sq;
    int missing = (Y / X + X) / 2;
    printf("missing: %d\n", missing);
    
//     printf("sum: %d; sumsq: %d; real_sum: %d, real_sum_sq: %d\n",
//             sum, sumsq, real_sum, real_sum_sq);

    return 1;
}


