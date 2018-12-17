
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }

void print_array(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// lexicographically permutes an array of n elements
bool next(int *x, int n) {
    // find the rightmost x[i] which is smaller then x[i+1]
    int i = n - 1;
    do { i--; } while(x[i] >= x[i+1]);
    if(i < 0)
        return false; // all permutations enumerated
    // now we have:
    // x[i] < x[i+1] > x[i+2] > ... > x[n-2] > x[n-1]
    // find rightmost j such that x[i] < x[j]
    int j = n - 1;
    while(x[i] >= x[j]) j--;
    // we have: x[i] < x[j] where j = i+1 .. n-1
    swap(x[i], x[j]);
    // now elements x[i+1].. x[n-1] form a falling sequence => reverse it
    int r = n - 1, s = i + 1;
    while(s < r) {
        swap(x[s], x[r]);
        s++, r--;
    }
    return true;
}

// computes the next number after 'N' formed from the same digits
int next_number(int N, int *x, int n_digits) {

    int i;
    for(i = n_digits - 1; N != 0; i--) {
        x[i] = N % 10, N /= 10; // convert the number to an array of digits
    }
    if(!next(x, n_digits)) // compute the next permutation
        return 0; // all numbers enumerated

    for(i = 0, N = 0; i < n_digits; i++) { // convert back to a number
        N = N*10 + x[i];
    }
    return N;
}

int main() {

    int n = 10; // max no of digits
    int *x = new int[n+1], *y = x + 1;
    x[0] = n+1; // sentinel

    int N = 11553, n_digits = 5;
    while(1) {
        printf("next: %d\n", N);
        int Nprev = N;
        N = next_number(N, x, n_digits);
        if(Nprev >= N) {
            printf("ERROR: %d %d\n", Nprev, N);
            break;
        }

        if(N == 0) break;
    }
    delete []x;
    return 1;
}

