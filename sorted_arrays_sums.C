
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

void largest_sums(int *a, int *b, int n) {
    int ia = 0, ib = 0;
    int s = a[ia] + b[ib];
    printf("%d\n", s);
 
    std::vector< std::pair< int, int > > stack;
    int prev = -1;

    bool pivot_found = false;
    int pivot = 0, safe_ia = 0, start_i = 0;
    int start_b = 0;
    ia = 0, ib = 0;
    while(1) {

        while(!pivot_found) {

        if(ia == n - 1) { // this is a last column
            printf("!!!!!!!!!!! ia = %d\n", ia);
            ia = start_i;
            start_b++;
        }       
            
        // compute row difference
        int diffx = a[0] - a[ia + 1] + b[0] - b[start_b],
            diffy = a[0] - a[safe_ia] + b[0] - b[start_b + 1];

        if(diffx <= diffy) {
            ia++;

            s = a[ia] + b[start_b];
            printf("ia: %d; ib: %d; %d\n", ia, start_b, s);
//             printf("diffx: %d; diffy: %d\n", diffx, diffy);
        } else {
            start_i = safe_ia;
            safe_ia = ia + 1;
            ia = start_i;
            
            pivot = a[safe_ia] + b[start_b];
            pivot_found = true;
            ib = start_b + 1;
            printf("pivot found: %d\n\n", pivot);
//             return;
        }

        if(ia == n-1|| ib == n-1)
           break;

        }
//         printf("ia: %d; ib: %d\n", ia, ib);

        if(a[ia] + b[ib] < pivot) {
            if(ia == start_i) {
                ia = safe_ia;
                pivot_found = false;
                printf("need new pivot at: (%d; %d)\n", ia, ib);
//                 return;
            } else {
                ia = start_i; ib++;
//                 printf("next: ia: %d; ib: %d\n", ia, ib);
                if(ib == n) {
                    ia = safe_ia;
                    pivot_found = false;
                }
            }
            continue;
        }

        if(ia == n/*|| ib == n*/)
           break;

        s = a[ia] + b[ib];
        printf("ia: %d; ib: %d; %d\n", ia, ib, s);

        ia++; // go over rows
//             if(prev == 0) {
//                 printf("push: %d %d\n", ia, ib);
//             stack.push_back(std::make_pair(ia, ib));
//             }
//             prev = 1;
   }
}

int main() {
//    int a[] = {15,11,9,8,4,3};
//    int b[] = {8,7,5,3,2,1};
    int a[] = {10,9,4,2,1};
    int b[] = {7,5,4,3,1};
    int n = sizeof(a)/sizeof(int);

//     largest_sums(a,b,n);

    return 0;
}