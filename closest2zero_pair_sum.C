
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

void closest2zero_pair(int *a, int n) {
 
    int i1 = 0, i2 = n-1, so_far = 100000;
    int ii = -1, jj = -1;
    
    while(i1 < i2) {
        
        int s = a[i1] + a[i2];
        if(std::abs(s) < so_far) {
            so_far = std::abs(s);
            ii = i1, jj = i2;
        }
        if(s < 0)
            i1++;
        else if(s > 0)
            i2--;
        else break;
    }
    printf("found: %d %d\n", a[ii], a[jj]);
}


int main() {
//     int a[] = {-6, -4, 1, 3, 5, 10, 17};
//     int n = sizeof(a) / sizeof(int);
    srand(time(NULL));
    
    int n = 20;
    std::vector< int > s(n);
    int N = 100;
    for(int i = 0; i < n; i++) {
        s[i] = rand() % N - N/5;
    }
    std::sort(s.begin(), s.begin() + n);
    
    printf("s = [");
    for(int i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");

    closest2zero_pair(s.data(), n);
    return 1;
}

