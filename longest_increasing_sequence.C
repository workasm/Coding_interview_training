
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <stdio.h>

/**
Find the all the sequence from Unsorted array.

Example : {2,4,6,8,10,14,11,12,15,7} is the unsorted array. We have to find out possible sequences.
Output would be :
Seq 1 : {2,4,6,8,10,11,12,15}
Seq 2 : {2,4,6,8,10,14,15}
Seq 3 : {2,4,6,7}

Note : if I pick any element in array than next element would be grater than the previous element.

*/

std::vector< int > seq;
// print sequences recursively
void print_recursive(int *a, int i,
        const std::vector< std::vector< int > >& S) {
    //
    if(i == -1) {
        printf("[");
        for(int j = seq.size()-1; j >= 0; j--) {
            printf("%d ", seq[j]);
        }
        printf("]\n");
        return;
    }
    
    printf("traversing S[%d]\n", i);
    seq.push_back(a[i]);
    for(int j = 0; j < S[i].size(); j++) {
        print_recursive(a, S[i][j], S);
    }
    seq.pop_back();
}

void longest_increasing_sequence(int *a, int n) {
    // S[i] - indices of previous elements in sequences ending at a[i]
    // PEPE: in other words, this is like a 'parent' pointer in an n-ary tree
    std::vector< std::vector< int > > S(n);
    // L[i] - marks the last (lergest) elements in sequences
    std::vector< int > L(n);
    // this is a terminating symbol
    S[0] = std::vector< int >(1, -1);
    L[0] = 1;
    for(int i = 1; i < n; i++) {
        int maxl = -1;
        //S[i] = std::vector< int >(1, -1); // put terminating symbol
        L[i] = 1; // mark the beginning of a new sequence
        for(int j = i - 1; j >= 0; j--) {
            if(a[j] < a[i] && a[j] > maxl) { 
                // means that from a[i] we can go to a[j]
                S[i].push_back(j); // merge a sequence starting at 'j' with 'i'
                maxl = a[j];
                L[j] = -1; // element 'j' is now a part of larger sequence
            }
        }
        if(S[i].size() == 0)
            S[i].push_back(-1);
    }
    
    int k = 8;
    printf("S[%d] elems: [", k);
    for(int i = 0; i < S[k].size(); i++) {
        printf("%d ", S[k][i]);
    }
    printf("]\n");
    
    printf("L elems: [");
    for(int i = 0; i < n; i++) {
        printf("%d ", L[i]);
    }
    printf("]\n");
    
    // print the resulting sequences
    for(int i = 0; i < n; i++) {
        if(L[i] == -1)
            continue;
        print_recursive(a, i, S);
    }
}

int main() {
    int a[] = {2,4,6,8,10,14,11,12,15,7};
    //int a[] = {5,1,6,8,7,15,2,45,3,6};
 //   int a[] = {10,3,6,7,2,4,6,8,88,3,4,5,76,10,1,11,91,15,17};
    int n = sizeof(a) / sizeof(int);
    longest_increasing_sequence(a, n);
    return 1;
}

