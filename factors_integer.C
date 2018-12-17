
#include <stdio.h>
#include <memory.h>
#include <string.h>

#include <set>

#define rows 4
#define cols 4

void compute_factors(int n) {

    std::set< int > fc;

    fc.insert(1);
    fc.insert(n);

    int x;
    for(x = 2; x < n/2+1; x++) {

        if(n % x != 0)
            continue;
        if(!fc.insert(x).second)
            break;
        if(!fc.insert(n/x).second)
            break;
    }
    printf("break at x = %d\n", x);

    for(typeof(fc.begin()) it = fc.begin(); it != fc.end(); it++) {

        printf("%d  ", *it);
    }
    printf("\n");
}


int main() {

    compute_factors(180);
    
    return 1;
}


