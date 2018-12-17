
#include <stdio.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void missing_ints(int *A, int n) {

    // numbers are from 1 to n
    for(int i = 0; i < n; i++) {
        int idx = abs(A[i]) - 1;
        if(A[idx] > 0) 
            A[idx] = -A[idx];
    }
    for(int i = 0; i < n; i++) {
        if(A[i] > 0)
            printf("number %d missing\n", i+1);
    }
}

main() {
    
    int A[] = {2, 3, 3, 1, 5, 5, 6, 7, 4};

    missing_ints(A, 9);

}

