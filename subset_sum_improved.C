
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

// print sequences recursively
void print_recursive(int *a, const std::vector< std::vector< int > >& F,
        int s) {
 
    const std::vector< int >& part = F[s];
    if(part.empty()) {
        printf("[");
        for(int j = seq.size()-1; j >= 0; j--) {
            printf("%d ", seq[j]);
        }
        printf("]\n");
        return;
    }
     
    for(int i = 0; i < part.size(); i++) {
        seq.push_back(a[part[i]]);
        print_recursive(a, F, s - a[part[i]]);
        seq.pop_back();
    }
}

// checks if its feasible to get a sum of 's' from elements of 'a'
void subset_sum(int *a, int n, int S) {
    
    // feasible[s] = 1 if it's possible to get a subset sum of 's' 
    std::vector< int > feasible(S+1, 0);
    
    //! F[s] - is a vector indices (at most n) representing which elements
    //! contribute to the subset sub of 's'. In other words, if i = F[s], then
    //! a[i] contributes to the sub of 's'. Accordingly, the tail of the 
    //! subset sequence is given by F[s - a[i]]
    
    std::vector< std::vector< int > > F(S+1);
    feasible[0] = 1; // empty subset to get a sum of zero

    for(int i = 0; i < n; i++) {
               
        //! use this if elements can be repeated in a subset sum
        //! for(int s = 1; s <= S; s++) {
        
        //! this is if we don't allow repetitions:
        for(int s = S; s >= 1; s--) {
            // see if we can use a[i] to get a sum of 's'
            if(s >= a[i] && feasible[s - a[i]] == 1) {
                feasible[s] = 1;
                F[s].push_back(i);
            }
        }
    }
    
    for(int s = 0; s <= S; s++) {
        if(!feasible[s]) 
            continue;
        printf("sum = %d; feasible\n", s);
        print_recursive(a, F, s);
        
        printf("===========\n");
    }
    
}

int main(){

    int a[] = {2,3,5,9,10,11};
    int n = sizeof(a) / sizeof(int);

    subset_sum(a, n, 50);
}

