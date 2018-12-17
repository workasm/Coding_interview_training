
#include <stdio.h>
#include <iostream>
#include <bitset>
#include <string>
// k-elements sets of x

int next(int n) {

    int lo = n & -n;       // lowest one bit
    int lz = (n + lo) & ~n;      // lowest zero bit above lo
    n |= lz;                     // add lz to the set
    n &= ~(lz - 1);              // reset bits below lz
    n |= (lz / lo / 2) - 1;      // put back right number of bits at end
    return n;
}

int prev(int n) {
    
    int y = ~n;
    y &= -y; // lowest zero bit
    n &= ~(y-1); // reset all bits below y
    int z = n & -n; // lowest set bit
    n &= ~z;        // clear z bit
    n |= (z - z / (2*y)); // add requried number of bits below z
    return n;
}

typedef unsigned long ulong;

class combination_lex
// Combinations n choose k (lexicographic order)
{
public:
    ulong *x_;    // combination: k elements 0<=x[j]<k in increasing order
    ulong n_, k_; // Combination (n choose k)

public:
    combination_lex(ulong n, ulong k)
    {
        n_ = n;  k_ = k;
        x_ = new ulong[k_];
        first();
    }

    ~combination_lex()  { delete [] x_; }


    void first()
    {
        for (ulong k=0; k<k_; ++k)  x_[k] = k;
    }

    void last()
    {
        for (ulong i=0; i<k_; ++i)  x_[i] = n_ - k_ + i;
    }

    ulong next()
    // Return smallest position that changed, return k with last combination
    {
        if ( x_[0] == n_ - k_ )  // current combination is the last
        { first();  return k_; }

        ulong j = k_ - 1;
        // easy case:  highest element != highest possible value:
        if ( x_[j] < (n_-1) )  { ++x_[j];  return j; }

        // find highest falling edge:
        while ( 1 == (x_[j] - x_[j-1]) )  { --j; }

        // move lowest element of highest block up:
        ulong ret = j - 1;
        ulong z = ++x_[j-1];

        // ... and attach rest of block:
        while ( j < k_ )  { x_[j] = ++z;  ++j; }

        return  ret;
    }

    ulong prev()
    // Return smallest position that changed, return k with last combination
    {
        if ( x_[k_-1] == k_-1 )  // current combination is the first
        { last();  return k_; }

        // find highest falling edge:
        ulong j = k_ - 1;
        while ( 1 == (x_[j] - x_[j-1]) )  { --j; }

        printf("j = %d %d\n", j, x_[j-2]);

        ulong ret = j;
        --x_[j];  // move down edge element

        // ... and move rest of block to high end:
        while ( ++j < k_ )  x_[j] = n_ - k_ + j;

        return  ret;
    }

    const ulong * data()  const  { return x_; }

    void print_set(const char *bla=0)  const
    { 
        for(int i = 0; i < k_; i++)
            printf("%d ", x_[i]);
        printf("\n\n");
    }
// 
//     void print_deltaset(const char *bla=0)  const
//     { ::print_set_as_deltaset(bla, x_, k_, n_); }
};
// ---

// rotate strings: concatenate with itself and do: ABCDABCD
// and do strstr()

int main() {

    combination_lex lex(7, 3);
    lex.x_[0] = 1;
    lex.x_[1] = 2;
    lex.x_[2] = 3;
    lex.print_set();
    lex.prev();
    lex.print_set();

    int n = 76;
    for(int i = 0; i < 30; i++) {
        int nx = next(n);
        int pv = prev(nx);
    
        int ny = (n & (n-1)) + (n ^ (n-1)) + 1;

        printf("n = %d next = %d prev(next) = %d ny = %d\n",
            n, nx, pv, ny);

        std::string s = std::bitset<32>(n).to_string();
        std::next_permutation(s.begin(), s.end());
        std::cout<<std::bitset<32>(s).to_ulong()<<std::endl; // prints 81

        n = nx;
    }

       
    return 1;
}

