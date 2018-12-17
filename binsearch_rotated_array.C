
#include <stdio.h>
#include <memory.h>
#include <string.h>

// A[] - rotated sorted array
bool binary_search(int *A, int n) {

    int l = 0, r = 1;
    while(1) { // first phase: find the array bounds

        if(r >= n) {
            r = n - 1;
        }

        if(A[l] <= A[r]) {
            if(r == n - 1) {
                printf("array is sorted\n");
                break;
            }

            l = r;
            r = r*2;
        } else
            break;
    }
    printf("crossover between %d(%d) -- %d(%d)\n",
            l, A[l], r, A[r]);

    // we have here: A[l] > A[r]

    // second phase: run an ordinary binary search with account for
    // the terminating symbol '$'
    while(1) {
        int mid = (l + r) / 2;
        int x = A[mid];

        if(x > A[l])
            l = mid + 1;
        else
            r = mid;
        if(l == r) {
            printf("found: %d(%d)\n", l, A[l]);
            break;
        }
        printf("mid: %d(%d)\n", mid, A[mid]);

//         break;
/*
        if(a == '$' || x < a) {
            r = mid;
        } else if(x > a) {
            l = mid + 1;
        } else  // gotcha !!
           return true;
        if(l == r)
            return false; // not found*/
    }
    return true;
}


int main() {

    int a[] = {127,200,2,4,4,5,7,9,16,23,45,100,125};
    int n = sizeof(a) / sizeof(n);

    binary_search(a, n);

    return 1;
}


