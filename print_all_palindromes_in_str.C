
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>

/**
Write a program that prints all the sub string that is palindrome within a input String. For e.g For input String "abbcacbca" output should be: [cac, bcacb, cbc, acbca, bb]
**/

char buf[256];

void print_palindromes(const char *str) {

    int len = strlen(str);
    int even = 1; // start with even-length palindrome

    for(int i = 1; i < len; ) {

        int istart, iend;
        if(even) {
            istart = i - 1, iend = i;
        } else { // odd-length palindrome
            istart = i - 1, iend = i + 1;
        }
        while(istart >= 0 && iend < len) {

            if(str[istart] != str[iend])
                break;
            strncpy(buf, str + istart, iend-istart+1);
            buf[iend-istart+1]='\0';
            printf("%s \n", buf);
            istart--, iend++;
        }

        if(even == 0)  // alternate looking for odd/even palindromes
            i++;
        even ^= 1;
    }
}

int main() {
    const char *str = "aaaaaaaaaaaaaaaaa";///"abbcacbcbcbcbcbcbca";
    print_palindromes(str);
    return 1;
}