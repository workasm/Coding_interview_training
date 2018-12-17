
#include <stdio.h>


void shuffle(int *A, int n) {
// shuffle n cards
    for(int i = n-1; i >= 1; i--) {
        int r = rand() % (i+1); // r = [0, i]
        swap(A[i], A[r]);
    }
}








