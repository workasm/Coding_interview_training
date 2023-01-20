
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <map>

// #include <math.h>
#include <stdio.h>

std::vector< int > seq;

int gg_wanted = 17;

//! \c sum that we wish to achieve
//! \c idx - last used element
void search_recursive(int *a, int n, int i, int sum, char *expr) {

    if(i >= n) {
        if(sum == 0)
            printf("%s = %d\n", expr, gg_wanted);
        return;
    }
    
    char bbf[64];
    int len = strlen(expr);
    
    sprintf(bbf, " + %d", a[i]);
    strcpy(expr + len, bbf);
    
//     printf("%d: expr = %s \n", i, expr);
    search_recursive(a, n, i+1, sum-a[i], expr);
    
    expr[len] = '\0';
    sprintf(bbf, " - %d", a[i]);
    strcat(expr + len, bbf);
    
//     printf("%d: expr = %s \n", i, expr);
    search_recursive(a, n, i+1, sum+a[i], expr);
    
    expr[len] = '\0';
}

int main(){
    
    char expr[256];
    expr[0] = '\0';

    int a[] = {1,2,3,5,6,7,11};
    int n = sizeof(a) / sizeof(int);

    search_recursive(a, n, 0, gg_wanted, (char *)expr);
}

