

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

/** 25-26,83-84,85-86,89-90,93-94,95-96,103-104,107-108,109-110,113-114,117-118,119-120,123-124,133-134,149-150,151-152,153-154,155-156,157-158,159-160
*/

void add_char(char c) {
    // pointers to keep track of odd and even-length palindromes
    static int odd = 0, even = -1;
    static int idx = 0;     // current position in the stream
    static char stream[256];
    static bool same_char = true;

    stream[idx] = c;
    stream[idx+1] = '\0';

    if(same_char && idx > 0 && c != stream[idx-1]) {
        same_char = false;
    }
    if(same_char) 
        printf("palindrome: %s\n", stream);
    
    if(odd >= 0 && stream[odd] == c) {
        odd--;
        if(odd < 0) {
            printf("odd palindrome: %s\n", stream);
            odd = idx - 1;
        }
    } else
        odd = idx - 1;
    if(even >= 0 && stream[even] == c) {
        even--;
        if(even < 0) {
            printf("even palindrome: %s\n", stream);
            even = idx;
        }
    } else
        even = idx;
    idx++;

    printf("%c: odd: %d; even: %d\n", c, odd, even);
//     printf("cacac");
}

int main() {
    const char *s = "bcacacb";
    for(int i = 0; s[i] != 0; i++)
        add_char(s[i]);
    return 0;
}



