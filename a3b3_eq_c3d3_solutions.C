

#include <stdio.h>

/*
Write all solutions for a^3+b^3 = c^3 + d^3, where a, b, c, d lie between [0, 10^5] in at least O(n^2) complexity*/

void compute() {
 
    int a1 = -1, b1 = 1, c1 = -1, d1 = 1,
        a2 = 3, b2 = -3, c2 = 3, d2 = -3;
        
    int num = c1*c1*c2 + d1*d1*d2 - a1*a1*a2 - b1*b1*b2;
    int den = a1*a2*a2 + b1*b2*b2 - c1*c2*c2 - d1*d2*d2;
    
    if(den != 0 && num % den == 0) {
        int t = num / den;
        
        int a3 = a1 + t*a2,
            b3 = b1 + t*b2,
            c3 = c1 + t*c2,
            d3 = d1 + t*d2;
            
        printf("got sol: %d^3 + %d^3 = %d^3 + %d^3\n", 
               a3, b3, c3, d3);
        
    }
}


int main() {

    compute();
    return 1;
}
