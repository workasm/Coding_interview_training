
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }

void print_array(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void zero_subarray(int *a, int n)  {

    for(int i = 1; i < n; i++) {
        a[i] = a[i] + a[i - 1];
    }
    print_array(a, n);
}

int main() {

    int a[] = {1, 2, -4, 3, 6, -9, 8};
    int n = sizeof(a) / sizeof(int);

    zero_subarray(a, n);
    return 1;
}


