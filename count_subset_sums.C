
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

void print_array(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n\n");
}

// Given a set of numbers [1-N] . Find the number of subsets such that the sum of numbers in the subset is a prime number.
// 16 

// subsets of [1..n] which sum up to 'x'
void find_subsets(int n, int x) {

    int s = 1, cnt = 0;
    for(; s < (1 << n); s++) {
        int sum = 0, i = 1, t = s;
        while(t != 0) {
            if(t & 1)
                sum += i;
            t >>= 1; i++;
        }
        if(sum == x) {
            cnt++;
//             printf("[");
//             int i = 1, t = s;
//             while(t != 0) {
//                 if(t & 1)
//                     printf("%d ", i);
//                 t >>= 1; i++;
//             }
//             printf("]\n");
        }
    }
    printf("%d: %d\n", x, cnt);
}


int main() {

    int n = , x;

    for(x = 0; x <= n*(n+1)/2; x++) {
        find_subsets(n, x);
    }

    return 1;
}