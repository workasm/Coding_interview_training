
#include <iostream>
#include <vector>
#include <stdio.h>

void subset_sum(int *A, int n) {

    int N = 0, P = 0, i, s;
    for(i = 0; i < n; i++) {
        if(A[i] < 0)
            N += A[i];
        else
            P += A[i];
    }

    //! idxs[i][s] is true if A[i] contributes to the subsum 's'
    //! Q[i][s] is true if there is a subset of numbers in [0..i] which
    //! sums up to 's'
    std::vector< std::vector< int > > Q(n), idxs(n);
    
    for(i = 0; i < n; i++) {
        Q[i] = std::vector< int >(P + 1, false);
        idxs[i] = std::vector< int >(P + 1, false);
//         idxs[0][A[i]] = true;
    }
    Q[0][A[0]] = true;
    idxs[0][A[0]] = true;

    for(i = 1; i < n; i++) {
        
        for(s = 0; s <= P; s++) {
            Q[i][s] = Q[i - 1][s] | (A[i] == s);
            // element A[i] contributes to the sum 's'
            idxs[i][s] = (A[i] == s); 

            if(s >= A[i]) {
                Q[i][s] |= Q[i - 1][s - A[i]];
                // element A[i] contributes to the sum 's'
                idxs[i][s] |= Q[i - 1][s - A[i]]; 
            }
        }
    }

    for(s = 0; s <= P; s++) {
        if(!Q[n-1][s]) // no such sum
            continue;

        printf("\nsum: %d; elements: [", s);

        i = n - 1;
        int t = s;
        while(1) {
            if(i < 0 || t < 0)  
                break;
            if(idxs[i][t]) { //! if A[i] is used for the subsum 't'
                    //! look whether A[i-1] is used for the subsum (t - A[i])
                printf("%d ", A[i]);
                t = t - A[i];
            }
            i--;
        }

//         for(i = 0; i < n; i++) 
//         printf("Q[n-1][%d] = %d\n", s, Q[n-1][s]);
//             if(idxs[i][s])
//                 printf("%d ", A[i]);
        printf("]\n");
    }
    //! Q[n-1][s] - true if there is a subset of 'A' which sums up to 's'
}


//! partition an array in two parts with equal average sum:
//! just run subset sum problem keeping track of the number of elements
//! 

int main() {

    int x[] = {7, 3, 4, 1, 6, 8, 9};
    int n = sizeof(x) / sizeof(int);
    subset_sum(x, n);
   

    return 1;
}
