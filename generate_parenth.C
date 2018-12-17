
#include <stdio.h>

int n_total = 3;

void parenth(int n_open, int n_closed, int num) {

    if(n_closed == n_total) {
        int mask = 1 << (2*n_total-1);            
        while(mask) {
            putchar(num & mask ? '(' : ')');
            mask >>= 1;
        }
        putchar('\n');
        return;
    }
    
    num *= 2;
    if(n_closed < n_open) // closing parenth encoded as 0
        parenth(n_open, n_closed + 1, num);
     
    if(n_open < n_total) // opening parenth as 1
        parenth(n_open + 1, n_closed, num + 1);
}


int main() {
    parenth(0, 0, 0);
    return 1;
}

