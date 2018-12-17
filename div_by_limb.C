
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <math.h>

#include <gmp.h>

// divides a multi-precision integer a[0..n-1] by a single word c
void div_by_limb(const unsigned *a, unsigned n, unsigned c) {

    typedef unsigned long long uint64;

    unsigned c_norm = c, sh = 0;
    while((c_norm & 0xC0000000) == 0) { // make sure the 2 MSB are set
        c_norm <<= 1; sh++;
    }
    // precompute the inverse of 'c'
    double inv1 = 1.0 / (double)c_norm, inv2 = 1.0 / (double)c;
    unsigned i, r = 0;

    printf("\nquotient: "); // quotient is printed in a loop
    for(i = n - 1; (int)i >= 0; i--) { // start from the most significant digit
        unsigned u1 = r, u0 = a[i];
        union {
            struct { unsigned u0, u1; };
            uint64 x;
        } s = {u0, u1}; // treat [u1, u0] as 64-bit int
        // divide a 2-word number [u1, u0] by 'c_norm' using floating-point
        unsigned q = floor((double)s.x * inv1), q2;
        r = u0 - q * c_norm;
        // divide again: this time by 'c'
        q2 = floor((double)r * inv2);

/*        r = s.x % c_norm;
        unsigned q = s.x / c;

        if(r != r2) {
            printf("FATAL :%d: %u %u\n", i, r, r2);
        }*/
        //         uint64 ss = s.x-r2;
//         printf("%x; %x; %x\n", q<<sh, q2, r / c);

        q = (q << sh) + q2; // reconstruct the quotient
        printf("%x", q);
    }

    r %= c; // adjust the residue after normalization
    printf("; residue: %x\n", r);
}

int main() {
    mpz_t z, quo, rem;
    mpz_init(z); // this is a dividend
    mpz_set_str(z, "9999999999999999999999999999999", 10);
    unsigned div = 9; // this is a divisor
    div_by_limb((unsigned *)z->_mp_d, mpz_size(z), div);
    mpz_init(quo); mpz_init(rem);
    mpz_tdiv_qr_ui(quo, rem, z, div); // divide 'z' by 'div'
    gmp_printf("compare: Quo: %Zx; Rem %Zx\n", quo, rem);
    mpz_clear(quo);
    mpz_clear(rem);
    mpz_clear(z);
    return 1;
}


