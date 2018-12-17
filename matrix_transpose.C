
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>

// in:  n rows; m cols
// out: n cols; m rows
void matrix_transpose(int *a, int n, int m) {
    int i, j;
    printf("\nin: %d x %d\n", n, m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) 
            printf("%d ", a[i*m + j]);
        printf("\n");
    }
    for(int k = 0; k < n*m; k++) {
        int idx = k;
        do { // calculate index of the original array
            idx = (idx % n) * m + (idx / n);
        } while(idx < k);
        std::swap(a[k], a[idx]);
    }
    printf("\nout: %d x %d\n", m, n);
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", a[i*n + j]);
        printf("\n");
    }
}

int main() {
    int n = 6, m = 3; // n rows, m cols
    int a[] = {1,1,1,1, 2,2,2,2, 3,3,3,3, 4,4,4,4,2,2};
    matrix_transpose(a, n, m);
    return 1;
}


