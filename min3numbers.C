
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
// Given three arrays A,B,C containing unsorted numbers. Find three numbers a, b, c from each of array A, B, C such that |a-b|, |b-c| and |c-a| are minimum
// Please provide as efficient code as you can.
// Can you better than this ???


void min3elements(int *A, int *B, int *C, int n) {
 
    int mins = 1e6, i1=0, i2=0, i3=0;
    int ia=0, ib=0, ic=0;
    
    while(i1 < n-1 || i2 < n-1 || i3 < n-1) {
        int sum = abs(A[i1]-B[i2]) + 
            abs(A[i1]-C[i3]) + abs(B[i2]-C[i3]);
        
        if(mins > sum) {
            mins = sum;
            ia = i1, ib = i2, ic = i3;
        }
        
        if(A[i1] < B[i2] && i1 < n-1 && i3 < n-1) {
            if(A[i1] < C[i3] && i1 < n-1)
                i1++;
            else
                i3++;
        } else {
            if(B[i2] < C[i3] && i2 < n-1)
                i2++;
            else
                i3++;
        }
    }
    
    printf("found no s A[%d] = %d; B[%d] = %d; C[%d] = %d\n",
           ia, A[ia], ib, B[ib], ic, C[ic]);
    
}

int main() {

    int A[] = { -3, -2, 0, 0, 1, 4};
    int B[] = { -10, -8, -5, -3, -1, 20};
    int C[] = { 1, 5, 10, 15, 20, 5};
    int n = sizeof(A) / sizeof(int);
    min3elements(A, B, C, n);
    
    
    return 1;
}
