
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <map>

#include <math.h>
#include <stdio.h>

void swap_sort(int *a, int n) {
 
    int k;
    for(int i = 0; i < n-1; i++) {
        k = i;
        for(int j = i+1; j < n; j++) {
            if(a[k] > a[j])
                k = j;
        }
        std::swap(a[k], a[i]);
    }
    
    for(int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
}

void num_perfect_square_parts(int n) 
{
    std::vector< int > a(n + 1, n*2);
    a[0] = 0; // 0 parts to get 0!
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
     
            int dif = i - j, num = a[j];
            int sq = (int)sqrtf(dif);
            if(dif == sq * sq) { // dif is perfect square
                num += 1;
            } else { // fill with ones
                num += dif;
            }
            a[i] = std::min(a[i], num);
        }
        
        printf("a[%d] = %d\n", i, a[i]);
    }
    
    
}

int main() {
    int a[] = {4,6,7,1,43,5,-1,4,9,3};
    int n = sizeof(a)/sizeof(int);
    swap_sort(a, n);
//     num_perfect_square_parts(40);
    return 1;
}

