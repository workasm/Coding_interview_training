
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

void print_array(int *a, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n\n");
}


//implementation for positive ints without error checking
int divide(unsigned int a, unsigned int b)
{
    unsigned res = 0, bx = b;

    while(bx < a)
        bx *= 2;

    printf("a: %d; bx: %d\n", a, bx, res);

    // bx/2 < a <= bx
    while(a >= b) {
        res <<= 1;
        bx >>= 1;
        if(bx <= a) {
            a -= bx;
            res++;
        }
        printf("a: %d; bx: %d; res: %d\n", a, bx, res);
    }
    printf("div: %d; mod: %d\n", res, a);
}


// computes a = b*q + r with 0 <= r < b
void divide(unsigned a, unsigned b, unsigned& quo, unsigned& rem) {
    // suppose numbers are positive
    if(a < b) {
        quo = 0; rem = a;
        return;   
    }
    quo = 1;
    while(quo*b*2 <= a) {
         quo *= 2;
    }
    // here it holds that: quo*b <= a < quo*b*2
    if(quo * b == a) {
        rem = 0;
        return;
    }

    unsigned ql = quo, qr = quo*2, mid;
    while(1) {
        mid = (ql + qr) / 2;
        if(mid*b <= a && a < (mid+1)*b)
            break;
        if(mid*b < a) {
            ql = mid+1;
        } else {
            qr = mid;
        }
    }
    quo = mid, rem = a - quo * b;
}

int main() {

    int a = 1121341, b = 13;

    printf("CHECK: div: %d; mod: %d; test: %d\n", a/b, a%b, divide(a,b));

    return 1;
}


