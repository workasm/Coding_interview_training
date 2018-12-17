
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

/**
35721 -> 35753 (mirror the upper half)
35762 -> 35853 (increment the middle digit if given)
35972 -> 36063 (increment and mirror the upper half)
99999 -> 100001 (special case)

*/

void print_array(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n\n");
}

// finds a smallest palyndrome number x2 > x
int next_palyndrome(int x) {
    int digits[12], n, x2 = x;
    for(n = 0; x2 != 0; n++) {
        digits[n] = x2 % 10;
        x2 /= 10;
    }
    int n2 = n / 2, n2p1 = n2 + (n & 1);
    // first try replacing the lower digits with rev upper digits
    int rev_hi = digits[n2p1], exp = 10;
    for(int i = 1; i < n2; i++) {
        rev_hi = rev_hi * 10 + digits[n2p1 + i];
        exp *= 10;
    }
    int hi = x / exp, lo = x % exp; // extract lower and upper halves
    x2 = hi * exp + rev_hi;
    if(x2 > x)     // CHECKING RULE 1
        return x2;
    hi += 1; // increment 'hi' and construct the number again
    if(hi == exp) { // handle a special case when hi = '99...99'
        if(n & 1) { // here we return: 100..001
            x2 = hi * exp * 10 + 1;  
        } else {
            x2 = hi * exp + 1;
        }
        return x2; // CHECKING RULE 4 
    }
    int t = (n & 1) ? hi / 10 : hi; // divide out a middle digit if necessary
    rev_hi = t % 10;
    // calculate the reverse of 'hi' again
    for(int i = 1; i < n2; i++) {
        t /= 10;
        rev_hi = rev_hi * 10 + (t % 10);
    }
    x2 = hi * exp + rev_hi;
    return x2;  // RULE 2 and 3 (together)
}

int main() {
    int x = 35972;
    while(1) {
        printf("next: %d\n", x);
        int x2 = next_palyndrome(x);
        if(x2 <= x) {
            printf("FATAL: %d %d\n", x2, x);
            break;
        }
        x = x2;
    }
    return 1;
}
