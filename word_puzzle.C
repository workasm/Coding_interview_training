
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>
#include <stdio.h>
#include <string.h>

bool forbid[26][10]; // which combinations are forbidden

// const char *s1 = "accc",
//     *s2 = "bcaa",
//     *s3 = "dbad";

/*const char *s1 = "abcd",
    *s2 = "dbcc",
    *s3 = "cdda";*/
    //2275 + 5277 = 7552

int A[26]; // currently assigned digits
const char *s1 = "abcdcba",
    *s2 = "dbadcbb",
    *s3 = "bdbacdc";

int l1, l2, l3;

// which = 0: assign the i-th character of string 's1'
// which = 1: assign the i-th character of string 's2'
// carry: carry flag for integer addition
void assign(int i, int which, int carry) {
    // assign the i-th character of the 1st number
    if(which == 0) { 
        if(i == -1) { // all combinations checked
            if(carry == 1)
                return;
            for(int j = 0; j < l1; j++) {
                printf("%d", A[s1[j] - 'a']);
            }
            printf(" + ");
            for(int j = 0; j < l2; j++) {
                printf("%d", A[s2[j] - 'a']);
            }
            printf(" = ");
            for(int j = 0; j < l3; j++) {
                printf("%d", A[s3[j] - 'a']);
            }
            printf("\n");
            return;
        }
        int i1 = s1[i] - 'a';
        if(A[i1] != -1) {
            assign(i, 1, carry); // assign i-th digit of 2nd no
            return;
        }
        for(int d = 0; d < 10; d++) {
            A[i1] = d;
            assign(i, 1, carry);
        }
        A[i1] = -1;
        return;
    }
    // assign the i-th character of the 2nd number
    int x1 = A[s1[i] - 'a']; // s1 already assigned
    int i2 = s2[i] - 'a';
    int i3 = s3[i] - 'a';
    if(A[i2] != -1) {
        int sum = A[i2] + x1 + carry;
        int c1 = sum / 10;
        sum %= 10;
        if(A[i3] != -1) {  // mismatch
            if(A[i3] != sum)
                return;
            assign(i - 1, 0, c1);
            return;
        }
        A[i3] = sum;
        assign(i - 1, 0, c1);
        A[i3] = -1;
        return;
    }
    for(int d = 0; d < 10; d++) {
        A[i2] = d;
        int sum = A[i2] + x1 + carry;
        int c1 = sum / 10;
        sum %= 10;
        if(A[i3] != -1) {  // mismatch
            if(A[i3] != sum)
                continue;
            assign(i - 1, 0, c1);
        } else {
            A[i3] = sum;
            assign(i - 1, 0, c1);
            A[i3] = -1;
        }
    }
    A[i2] = -1;
}

int main() {
    memset(A, 0xff, sizeof(A));
    l1 = strlen(s1);
    l2 = strlen(s2);
    l3 = strlen(s3);
    assign(l1-1, 0, 0);
}

