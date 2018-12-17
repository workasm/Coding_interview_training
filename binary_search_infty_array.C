
#include <stdio.h>
#include <memory.h>
#include <string.h>

// infA[] - infinite array with '$' as a terminating character
bool binary_search(char *infA, char x) {

    int l = 0, r = 1;
    while(1) { // first phase: find the array bounds
        char a = infA[r - 1];
        // we found the valid range or hit the end of the data:
        // in either case we can bound the search space to [l; r]
        if(a == '$' || x < a) { 
            break;
        }
        if(x == a) // found the actual val
            return true;  
        // otherwise we keep on moving the right boundary
        l = r - 1, r = r * 2;
    }
    printf("'x' can only lie between [%c; %c]\n", infA[l], infA[r]);

    // second phase: run an ordinary binary search with account for
    // the terminating symbol '$'
    while(1) {
        int mid = (l + r) / 2;
        char a = infA[mid];
        if(a == '$' || x < a) {
            r = mid;
        } else if(x > a) {
            l = mid + 1;
        } else  // gotcha !!
           return true;
        if(l == r)
            return false; // not found
    }
}


int main() {

    int n = 1000;
    char *infA = new char[n];
    strncpy(infA, "bcdeghilopqruvwxy$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$", n);

    printf("%s\n", infA);

    printf("search: %d\n", binary_search(infA, 'i'));

    delete []infA;
    return 1;
}


