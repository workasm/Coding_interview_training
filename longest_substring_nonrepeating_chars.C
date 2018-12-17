
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>

#include <math.h>
#include <stdio.h>

/**
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for ?ABDEFGABEF? are ?BDEFGA? and ?DEFGAB?, with length 6. For ?BBBB? the longest substring is ?B?, with length 1. For ?GEEKSFORGEEKS?, there are two longest substrings shown in the below diagrams, with length 7. 
**/

void longest_substring_no_repeating_chars(const char *str) {

    int l = strlen(str);
    int ch[256];
    memset(ch, 0xff, 256*sizeof(int));

    int s = 0, e = 0, maxs = 0, maxe = -1;
    for(int i = 0; i < l; i++) {
        int previ = ch[str[i]];
        if(previ == -1 || previ < s) {
            previ = i;
            e = i;
            if(maxe - maxs < e - s) {
                maxe = e, maxs = s;
            }
        } else {
            s = previ + 1;
        }
        printf("s: %d; e: %d\n", s, e);
        ch[str[i]] = previ;
    }
    printf("from %c(%d) -- %c(%d)\n", str[maxs], maxs, str[maxe], maxe);
}


int main() {
    const char *str = "geeksforgeeks";
    longest_substring_no_repeating_chars(str);
    return 1;
}




