
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

/** 25-26,83-84,85-86,89-90,93-94,95-96,103-104,107-108,109-110,113-114,117-118,119-120,123-124,133-134,149-150,151-152,153-154,155-156,157-158,159-160
*/


struct node {
    int val;
    node *left;
    node *right;
};

node *append(node *parent, int which, int val) {

    node *x = new node;
    x->left = x->right = 0;
    x->val = val;

    if(parent != 0) {
        if(which == 0)
            parent->left = x;
        else
            parent->right = x;
    }
    return x;
}

void traverse(node *t1, node *t2) {

    if(t2 == 0) {
        if(t1 == 0)
            return;
        traverse(t1->left, 0);
        printf("%d\n ", t1->val);
        traverse(t1->right, 0);
        return;
    }

    if(t1 == 0) {
        traverse(0, t2->left);
        printf("%d\n ", t2->val);
        traverse(0, t2->right);
        return;
    }

    printf("going left: %d %d\n", t1->val, t2->val);
    traverse(t1->left, t2->left);
    if(t1->val >= t2->val) {
        // explore t1
        printf("t2 smaller: %d\n ", t2->val);
        node *s = t1->left;
        t1->left = 0;
        traverse(t1, t2->right);
        t1->left = s;
    } else {
        // explore t1
        printf("t1 smaller: %d\n ", t1->val);
        node *s = t2->left;
        t2->left = 0;
        traverse(t1->right, t2);
        t2->left = s;
    }
}

void destroy_tree(node *root) {

    if(root == 0)
        return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    delete root;
}

int main(){

    node *x, *y;
//     node *head = append(0, 0, 10);
//     node *l = append(head, 0, 4),
//          *r = append(head, 1, 25),
//          *lr = append(l, 1, 7);
//     x = append(lr, 0, 6),
//     append(x, 0, 5);
// 
//     node *head2 = append(0, 0, 7);
//     l = append(head2, 0, 6);
//     r = append(head2, 1, 11);
//     append(l, 0, 1);
//     node *rr = append(r, 0, 9);

    node *head = append(0, 0, 5);
    node *l = append(head, 0, 3);
        append(head, 1, 9),
        append(l, 0, 1),
        append(l, 1, 4);

    node *head2 = append(0, 0, 7);
    append(head2, 0, 6);
    node *r = append(head2, 1, 10);
        append(r, 0, 8);
        append(r, 1, 11);

    traverse(head, head2);

/*     traverse(head, 0);
     traverse(head2, 0);*/
    destroy_tree(head);
    destroy_tree(head2);
}





