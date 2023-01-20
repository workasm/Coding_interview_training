
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <map>

// #include <math.h>
#include <stdio.h>

std::vector< int > seq;


// checks if its feasible to get a sum of 's' from elements of 'a'
void find_bounds(int *a, int n, int val) {
    
    int beg = 0, end = n-1;
    // searching upper bound
    while(beg < end) {
        int mid = (beg + end)/2;
        if(!(val<a[mid])) {
            beg = mid+1;
        } else {
            end = mid;
        }
    }
    int upper_bnd = beg;
    
    beg = 0, end = n-1;
    while(beg < end) {
        int mid = (beg + end)/2;
        if(a[mid] < val) {
            beg = mid+1;
        } else {
            end = mid;
        }
    }
    int lower_bnd = beg;
    
    printf("[%d; %d]\n", lower_bnd, upper_bnd);
}

int main(){

    int a[] = {1,2,3,3,3,4,4,4,4,4,5,5,5,7,8};
    int n = sizeof(a) / sizeof(int);

    find_bounds(a, n, 4);
}

