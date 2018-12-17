
#include <stdio.h>

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }


void print_array(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n\n");
}

// established heap property for subtree rooted at start index
void sift_down(int *a, int start, int end) {

    // for node i: 2*i+1 - left child, 2*i+2 - right child
    // nodes parent: (i-1)/2
    int i = start;
    while(2*i+1 <= end) { // i has at least 1 child
        int child = 2*i+1;
        if(child < end && a[child+1] < a[child])
            child += 1;
        // child points to i's child with minimal value
        if(a[i] > a[child]) {
            swap(a[i], a[child]);
            i = child;
        } else 
            break;        
    }
}

// start is a limit of how far up the heap to sift,
// end is a node to sift up
void sift_up(int *a, int start, int end) {
    
    int i = end;
    while(i > start) {
        int parent = (i-1) / 2;
        if(a[parent] > a[i]) {
            swap(a[parent], a[i]);
            i = parent;
        } else 
            break;
    }
}

// establish heap property in top-down fashion
void heapify_up(int *a, int n) {
    
    int i = 1;
    while(i < n) {
        sift_up(a, 0, i);
        i++;
    }
}

// establish heap property for array a
void heapify(int *a, int n) {
    
    int start = (n - 1)/2; // index of the last parent node
                       // child nodes need not be heapified
    while(start >= 0) {
        sift_down(a, start, n-1);
        start--;
    }
}
 
void heapsort(int *a, int n) {

    heapify(a, n); 
    int end = n-1;
    while(end > 0) {
        swap(a[0], a[end]); // a[0] is minimal number
        end--;
        sift_down(a, 0, end);
    }
}

int main() {

    int a[] = {3, 5, 5,1, 5, 467, 56, 67, 567, 4, 53 ,443, 3,0, 6, 5};
    int n = sizeof(a)/sizeof(int);

    heapsort(a, n);
    print_array(a, n);
}


