
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }

void print_array(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// permutes recursively x[k].. x[n-1]: NOT in lexicographic order
void permute_recursive(int *x, int k, int n) {

    if(k == n-1) { // one element array
        print_array(x, n);
        return;
    }
    // permute x[k..n-1]
    for(int i = k; i < n; i++) {
        swap(x[k], x[i]); // fix x[k], permute x[k+1..n-1]
        permute_recursive(x, k+1, n);
        swap(x[k], x[i]); // fix kth element
    }
}

static int C = 1;
// permutes recursively x[k].. x[n-1]: NOT in lexicographic order
void permute_string(char *x, int k, int n) {

    if(k == n-1) { // one element array
        printf("%d: %s\n", C, x);
        C++;
        return;
    }
    // permute x[k..n-1]
    for(int i = k; i < n; i++) {
        if(k != i && x[k] == x[i])
            continue;
        swap(x[k], x[i]); // fix x[k], permute x[k+1..n-1]
        permute_string(x, k+1, n);
        swap(x[k], x[i]); // fix kth element
    }
}


std::vector< int > seq;

// lexicographic order
void permute_lex(int *x, int n, int n_placed) {

    if(n_placed == n) {
        print_array(seq.data(), n);
        return;
    }

    for(int i = 0; i < n; i++) {
        // look for the first element not equal 0
        if(x[i] == 0)
            continue;
        int c = x[i];
        x[i] = 0; // mark that this element already placed
        seq.push_back(c);
        permute_lex(x, n, n_placed + 1);
        x[i] = c; // restore this element
        seq.pop_back();
    }
}

static int count = 0;
// generate permitations of size 'k'
void permute_lex_size_k(int *x, int n, int n_placed, int k) {

    if(n_placed == k) {
        printf("%d: ", ++count);
        print_array(seq.data(), k);
        return;
    }

    for(int i = 0; i < n; i++) {
        // look for the first element not equal 0
        if(x[i] == 0)
            continue;
        int c = x[i];
        x[i] = 0; // mark that this element already placed
        seq.push_back(c);
        permute_lex_size_k(x, n, n_placed + 1, k);
        x[i] = c; // restore this element
        seq.pop_back();
    }
}

int main() {

    int n = 5;
    int *x = new int[n+1], *y = x + 1;
//    int *perms = new int[n+1];
    x[0] = n+1; // sentinel

    srand(time(NULL));
    for(int i = 0; i < n; i++) {
//         y[i] = (i*i*i+17) % n + 1;
        y[i] = i+1; // first permutation
    }

    char s[] = "abbc";
    n = strlen(s);
//     permute_string(s, 0, n);

    int a[] = {1, 2, 3, 4, 5};
    n = sizeof(a) / sizeof(int);
    
    permute_lex_size_k(a, n, 0, 3);

//     int niters = 200;
//     do {
//         print_array(y, n);
// 
//     } while(next(y, n) && niters--);

    delete []x;
    return 1;
}

