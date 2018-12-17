
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <vector>

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }

// printf n x m array
void print_2d_ary(std::vector< std::vector< int > >& a, int n, int m) {

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) 
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

// compute the number of partitions of 'n' in at most 'k' parts
void n_partitions(int n, int k)  {

    //int *p = new int[(n + 1) * (k + 1)];
    std::vector< std::vector< int > > p(k + 1);

    int i, j;
    for(i = 0; i <= k; i++) {
        p[i] = std::vector< int >(n + 1, 0);
        p[i][0] = 1; // #partitions of 0 using at most 'i' parts
    }
    
    for(i = 0; i <= n; i++) {
        p[0][i] = 0;  // p[0][i] = 0
        p[1][i] = 1;  // p[1][i] = 1
    }
    p[0][0] = 1;
    print_2d_ary(p, k, n);

    for(i = 1; i <= n; i++) {
        for(j = 2; j <= k; j++) {
            p[j][i] = p[j - 1][i];
            if(i >= j)
                p[j][i] += p[j][i - j];
            print_2d_ary(p, k, n);
        }
    }
    
    printf("# partitions: %d\n", p[k][n]);

//     delete []p;
}

int main() {

//     Cpp *p = new  Cpp;
//     p->pure();

    n_partitions(5, 3);

    return 1;
}


