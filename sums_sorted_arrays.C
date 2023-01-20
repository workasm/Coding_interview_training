
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>

#include <math.h>
#include <stdio.h>

/**
Given two sorted postive integer arrays A(n) and B(n) (W.L.O.G, let's
say they are decreasingly sorted), we define a set S = {(a,b) | a \in
A
and b \in B}. Obviously there are n^2 elements in S. The value of such
a pair is defined as Val(a,b) = a + b. Now we want to get the n pairs
from S with largest values.
*/

int *preprocess_array(int *a, int n) {
    
    int *b = (int *)calloc(n, sizeof(int));
    b[0] = 0;
    for(int i = 0; i < n - 1; i++) {
        b[i + 1] = a[i] - a[i + 1];
    }
    return b;
}


void largest_sums(int *a, int *b, int n) {

    int cnt = 0;
    int idx_a = 0;
    int idx_b = 0;

    int *answer = (int*)calloc(n, sizeof(int));
    if(a[n - 1] >= b[0]) {
        answer = a;
        goto finish;
    }
    if (b[n - 1] >= a[0]) {
        answer = b;
        goto finish;
    }

    {
    int *pre_a = preprocess_array(a,n);
    int *pre_b = preprocess_array(b,n);

    answer[cnt++] = a[idx_a] + b[idx_b];
    while (cnt < n) {
        printf("idx_a: %d; idx_b: %d; pre_a: %d; pre_b: %d\n", idx_a, idx_b,
                    pre_a[idx_a+1], pre_b[idx_b+1]);
        if (pre_a[idx_a+1] <= pre_b[idx_b+1]) {
            answer[cnt++] = a[++idx_a] + b[idx_b];
        } else {
            answer[cnt++] = a[idx_a] + b[++idx_b];
        }
    }
    }

finish:
    for(int i = 0; i < n; i++)
        std::cout << answer[i] << std::endl;
}

/**
bool flag = true;
    int prev_ai = 0, prev_bi = 1;

    int ai = 1, bi = 0, i;
    int sum;

    printf("(%d + %d) = %d\n", 0, 0, (A[0] + B[0]));
    sum = A[0] + B[1];

    for(i = 1; i < n + 3; i++) {
        if(B[bi] + A[ai] > sum) {
            printf("(%d + %d) = %d\n", ai, bi, (B[bi] + A[ai]));

        } else {
            sum = B[bi] + A[ai];

            std::swap(prev_bi, bi);
            std::swap(prev_ai, ai);

            printf("(%d + %d) = %d\n", ai, bi, (B[bi] + A[ai]));

            flag ^= 1;
        }

        if(flag)
            ai++;
        else
            bi++;
    }
    return 0;
*/



int main() {

/*    int A[]={30,20,10,1};
    int B[]={5,4,3,2};*/
    int A[]={ 10, 9, 4, 2, 1 };
    int B[]={ 7, 5, 4, 3, 1 };

/*    int A[]={ 11,9,7,6,4,3,1};
    int B[]={ 10,8,7,6,5,2,1};*/
    int n = sizeof(A) / sizeof(int);
    largest_sums(A, B, n);
    return 0;
}



