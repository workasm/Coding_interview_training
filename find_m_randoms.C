
#include <stdio.h>

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }

int *pick_m_randoms(int *a, int n, int m)
{
    if(m >= n)
        return 0;

    int *res = new int[m];    
    srand(time(0));

    for(int i = 0; i < m; i++) {
        
        int idx = rand() % (n - i);
        res[i] = a[idx];
        swap(a[idx], a[n - i - 1]);
    }
    return res;
}
