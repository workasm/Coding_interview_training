// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;

void find_3_elements(int *a, int n) {
    
    std::vector< int > l(n), r(n), lcnt(n), rcnt(n);
    
    l[0] = a[0], lcnt[0] = 1;
    int m = l[0];
    for(int i = 1; i < n; i++) {
        int c = lcnt[i-1];
        if(a[i] <= m) {
            m = a[i];
            c = 0;
        } 
        l[i] = m;
        lcnt[i] = c + 1;
    }
    
    r[n-1] = a[n-1], rcnt[n-1] = 1;
    m = r[n-1];
    for(int i = n-2; i >= 0; i--) {
        int c = rcnt[i+1];
        if(a[i] >= m) {
            m = a[i];
            c = 1;
        } 
        r[i] = m;
        rcnt[i] = c + 1;
    }
    
    for(int i = 0; i < n; i++) {
        //printf("%d: %d (%d)\n", i, l[i], lcnt[i]);   
        printf("%d: %d (%d)\n", i, r[i], rcnt[i]);   
    }
    int s = 0, e = n-1, which = 0;
    while(s < e) {
        printf("%d %d\n", s, e);
        if(l[s] < r[e] && a[s] < a[e] && lcnt[s] + rcnt[e] >= 3) {
            printf("found: %d(%d) %d(%d)\n", s, a[s], e, a[e]);
            break;
        }    
        if(which == 0)
            s++;
        else
            e--;
        which ^= 1;
    }
}

int main() {
    
    //int a[] = {4,5,2,1,4,9,1,3,7,6};
    //int a[] = {4,3,2,1,5,6};
    int a[] = {2,3,3,3,3,3,3,3,3,1,2,3};
    int n = sizeof(a) / sizeof(int);
    find_3_elements(a, n);    
    
    return 0;
}