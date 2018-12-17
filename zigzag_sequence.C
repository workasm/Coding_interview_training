
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

void print_array(int *a, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n\n");
}

// dp0[i] - max length of zigzag sequence using a subset of a[0..i] where
// the last difference is positive
// dp1[i] - same as above but the last difference is negative

// computes maximum zigzag sequence
int zigzag_sequence(int *a, int n) {

    int *dp = new int[n*2], *dp0 = dp, *dp1 = dp0 + n;

    for(int i = 0; i < n; i++) {
        dp0[i] = dp1[i] = 1;

        for(int j = 0; j < i; j++) {
            int s = a[i] - a[j];

            if(s > 0) {
                dp0[i] = std::max(dp1[j] + 1, dp0[i]);
            } else if(s < 0) {
                dp1[i] = std::max(dp0[j] + 1, dp1[i]);
            } 
        }
    }

    int len = std::max(dp0[n-1], dp1[n-1]);
    printf("dp0: %d; dp1: %d\n", dp0[n-1], dp1[n-1]);
    delete []dp;

    return len;
}

int test_zigzag(int *a, int n) {

    int len = 1, inext = 1, icur = 0;
    int d = a[inext] - a[icur];

    printf("[%d ", a[0]);
    if(d != 0) {
        len++; icur = inext;
        printf("%d ", a[1]);
    }
    inext++;

    for(; inext < n; inext++) {
        int d2 = a[inext] - a[icur];

        if(d2 == 0)
            continue;
        if(d == 0) {
            d = d2;
            continue;
        }
        if(d * d2 < 0) {
            printf("%d ", a[inext]);
            d = d2; icur = inext; len++;
        }
    }
    printf("]\n");
    printf("len = %d\n", len);
}

int main() {

    int a[] = {1,17,5,10,4,8,10,5,11};/*8,245,21,5,2,5,23,21,12};*/
    int n = sizeof(a) / sizeof(int);

    srand(time(NULL));
    std::random_shuffle(a, a + n);
    print_array(a, n);

    zigzag_sequence(a, n);
    test_zigzag(a, n);

    return 1;
}


