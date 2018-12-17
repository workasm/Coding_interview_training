
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

/** 25-26,83-84,85-86,89-90,93-94,95-96,103-104,107-108,109-110,113-114,117-118,119-120,123-124,133-134,149-150,151-152,153-154,155-156,157-158,159-160
*/

std::vector< int > seq_a, seq_b;

int sum_a = 0, sum_b = 0, sq_sum_a = 0, sq_sum_b = 0;
int xor_a = 0, xor_b = 0, and_a = -1, and_b = -1;

int ixor_a = 0, ixor_b = 0;

int xmin = -10, xmax = 10;

int bitrev(int x) {
//     int m = 0x55555555;
//     x = ((x & m) << 1) | ((x & ~m) >> 1);
//     m = 0x33333333;
//     x = ((x & m) << 2) | ((x & ~m) >> 2);
//     m = 0x0f0f0f0f;
//     x = ((x & m) << 4) | ((x & ~m) >> 4);
//     m = 0x00ff00ff;
//     x = ((x & m) << 8) | ((x & ~m) >> 8);
//     m = 0x0000ffff;
//     x = ((x & m) << 16) | ((x & ~m) >> 16);

    x ^= (x >> 1);
    x ^= (x >> 2);
    x ^= (x >> 4);
    x ^= (x >> 8);
    x ^= (x >> 16);
    return x;
}

int bitcount(int x) {

    x = ((x >> 1) & 0x55555555) + (x & 0x55555555);
    x = ((x >> 2) & 0x33333333) + (x & 0x33333333);
    x = ((x >> 4) & 0x0f0f0f0f) + (x & 0x0f0f0f0f);
    x += x >> 8;
    x += x >> 16;
    x &= 0xff;
    return x;
}

static int cnt = 0;

void explore(int n_left, int which, int last_set) {

    if(n_left == 0) {

        cnt++;
        if(cnt % 1000000000 == 0)
            printf("%u...\n ", cnt);

        
        if(sum_a != sum_b || sq_sum_a != sq_sum_b || xor_a != xor_b
                || ixor_a != ixor_b)
            return;
//         if(sum_a != sum_b || mul_a != mul_b || xor_a != xor_b)
//             return;

//         printf("%d %d\n", seq_a.size(), seq_b.size());
        int i, j, min_b = seq_b[0], max_b = seq_b[0],
                min_a = seq_a[0], max_a = seq_a[0];

        std::vector< int > tmp = seq_a;
        for(i = 0; i < seq_b.size(); i++) {
            for(j = 0; j < tmp.size(); j++) {
                if(seq_b[i] == tmp[j]) {
                    tmp[j] = -10000;
                    break;
                }
            }
            if(j == tmp.size()) // element not found
                break;
        }
        if(i == seq_b.size()) // permutations
            return;

        for(i = 0; i < seq_a.size(); i++) {
            int x = seq_a[i];
            if(min_a > x)
                min_a = x;
            else if(max_a < x)
                max_a = x;

            x = seq_b[i];
            if(min_b > x)
                min_b = x;
            else if(max_b < x)
                max_b = x;
        }

        int minc = 0, maxc = 0;
        for(i = 0; i < seq_b.size(); i++) {
            minc += (min_b == seq_b[i]);
            maxc += (max_b == seq_b[i]);
        }
        
        if(min_a != min_b || max_a != max_b)
             return;

//         printf(" %d %d %d %d ", min_a, min_b, max_a, max_b);
        printf("a: [");
        for(i = 0; i < seq_a.size(); i++) {
            printf("%d ", seq_a[i]);
        }
        printf("] -- b: [");
        for(i = 0; i < seq_b.size(); i++) {
            printf("%d ", seq_b[i]);
        }
        printf("]\n");
        printf("]; sum_a: %d; sum_b: %d; sq_sum_a: %d; sq_sum_b: %d; "
            "xor_a: %d; xor_b: %d %d -- %d\n\n",
               sum_a, sum_b, sq_sum_a, sq_sum_b, xor_a, xor_b, ixor_a, ixor_b);
//         
        return;
    }

    if(which == 0) {
    for(int x = last_set + 1; x <= xmax; x++) {
        int revx = bitrev(x);
        int nbits = bitcount(x);
        
        sum_a += x;
        sq_sum_a += (nbits + x*x);
        xor_a ^= x;
        ixor_a += revx;
        seq_a.push_back(x);
        explore(n_left, 1, last_set);
        seq_a.pop_back();
        sum_a -= x;
        sq_sum_a -= (nbits + x*x);
        xor_a ^= x;
        ixor_a -= revx;
    }
    } else {

    for(int x = xmin; x <= xmax; x++) {
        int revx = bitrev(x);
        int nbits = bitcount(x);
        
        sum_b += x;
        sq_sum_b += (nbits + x*x);
        xor_b ^= x;
        ixor_b += revx;
        seq_b.push_back(x);
        explore(n_left - 1, 0, last_set);
        seq_b.pop_back();
        sum_b -= x;
        sq_sum_b -= (nbits + x*x);
        xor_b ^= x;
        ixor_b -= revx;
    }
    }
}


int main() {
/*    int B[]={ 10,8,7,6,5,2,1};
    int n = sizeof(A) / sizeof(int);*/

    xmin = 1, xmax = 100;
    explore(50, 0, xmin-1);
    return 0;
}



