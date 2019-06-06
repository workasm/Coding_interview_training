
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>

// reconstruct a binary tree using post-order & in-order traversal

node *reconstruct_tree(int *post_order, int *in_order, int size) {

    if(size == 0)
        return 0;
    int root = post_order[size-1];

    int i = 0;
    while(in_order[i] != root) i++;

    t = new node;
    t->val = root;
    t->left = reconstruct_tree(post_order,
            in_order, i);

    t->right = reconstruct_tree(post_order + i,
            in_order + i + 1, size-i-1);

    return t;
}

int main() {

    printf("missing: %d\n", missing);
    
//     printf("sum: %d; sumsq: %d; real_sum: %d, real_sum_sq: %d\n",
//             sum, sumsq, real_sum, real_sum_sq);

    return 1;
}

