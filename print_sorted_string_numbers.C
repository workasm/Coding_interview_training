
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <map>
#include <stack>
#include <stdio.h>

/**Output top N positive integer in string comparison order. For example, let's say N=1000, then you need to output in string comparison order as below:
1, 10, 100, 1000, 101, 102, ... 109, 11, 110, ..
*/

void print_rec(char *str, int N) {
 
    if(atoi(str) > N)
        return;
    
    printf("%s ", str);
    int len = strlen(str);
    for(int i = 0; i < 10; i++) {
        str[len] = i + '0';
        str[len+1] = '\0';
        print_rec(str, N);
    }
}


int main(){
    char bbf[256];
    bbf[0] = '1';
    bbf[1] = '\0';
    
    print_rec(bbf, 1000);
    printf("\n");
    return 0;
}

