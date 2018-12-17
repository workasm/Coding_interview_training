
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>

int V[] = {1,3,5,7,9};  // which parts to use
int nv = sizeof(V) / sizeof(int);
static int cnt = 0;
std::vector< int > part; // container for partitions

// here i is the index in the array V the next part to be used
void generate_partitions(int x, int i) {
     if(x == 0) { // found a partition
        printf("%d: ", ++cnt);
        for(int j = 0; j < part.size(); j++) {
            printf("%d + ", part[j]);
        }
        printf("\n");
        return;
    }
    for(int j = i; j >= 0; j--) {
        int v = V[j];
        int y = x, c = 0;
        while(y >= v) { 
            part.push_back(v);
            y -= v; c++;
            generate_partitions(y, j-1);
        }
        while(c--) // remember how many times we pushed 'v'
            part.pop_back();
    }
}

int main() {
    int x = 11;
    generate_partitions(x, nv-1);
    return 1;
}


