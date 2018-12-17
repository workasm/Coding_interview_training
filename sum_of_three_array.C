

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <stdio.h>

void print_array(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n\n");
}

// check if a == b + c
void find_sum(int *a, int *b, int *c, int n) {
    for(int i = 0; i < n; i++) {
        int x = a[i];
        int l = 0, r = n - 1;
        for(; ;) {
            int s = b[l] + c[r];
            if(s == x) {
                printf("%d = %d + %d\n", x, b[l], c[r]);
                if(l < n - 1 && b[l] == b[l + 1])
                    l++;
                else 
                    r--;
            } else if(s < x) {
                l++;
            } else
                r--;
            if(l == n || r == -1)
                break;
        }
    }
    printf("brute force check:\n");
    for(int i = 0; i < n; i++) {
        int x = a[i];
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(x == b[j] + c[k]) {
                    printf("all: %d = %d + %d\n", x, b[j], c[k]);
                }
            }
        }
    }
}

int main() {

//     int a[] = {8, 9, 10, 11, 20, 22};
//     int b[] = {1, 5, 6, 6, 9, 11};
//     int c[] = {3, 4, 7, 11, 12, 15};

// A[i]-B[j]=C[k] => A[i] = B[j] + C[k]

    int c[] = {2,2,2,2};
    int b[] = {5,3,5,1};
    int a[] = {7,3,4,5};

     int n = sizeof(a) / sizeof(int);
//     int n = 7;
//     int *rr = new int[30];
//     int *a = rr, *b = a + n, *c = b + n;
//     srand48(time(NULL));
// 
//     int m = 20;
//     for(int i = 0; i < n; i++) {
//         a[i] = lrand48() % m;
//         b[i] = lrand48() % m;
//         c[i] = lrand48() % m;
//     }
    std::sort(a, a + n);
    std::sort(b, b + n);
    std::sort(c, c + n);

    print_array(a, n);
    print_array(b, n);
    print_array(c, n);

    find_sum(a, b, c, n);

//     delete []rr;
    return 1;
}