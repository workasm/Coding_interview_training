
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

// const char *str = "thisisawesome";
// 
// void tokenize() {
// 
//     dict[i][j] = true if str[i..j] is present in dictionary
//     word[i][j] = true if str[i..j] is a single word or consists of
//                         two or more valid words
// 
//     word[i][j] = word[i][k] && word[k][j] for all k = i..j
// }


struct node {
    int val;
    int sum;
    node *left;
    node *right;
};

node *append(node *parent, int which, int val) {

    node *x = new node;
    x->left = x->right = 0;
    x->val = val;
    x->sum = -1;

    if(parent != 0) {
        if(which == 0)
            parent->left = x;
        else
            parent->right = x;
    }
    return x;
}

void destroy_tree(node *root) {

    if(root == 0)
        return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    delete root;
}

enum { LEFT_NODE = 0, RIGHT_NODE };

// find all pairs in BST that sum up to given value 'k'

int check(node *t1, node *t2, int key) {
    int s = t1->val + t2->val;

    int which = 0;
    printf("compare: %d + %d\n", t1->val, t2->val);
    if(s == key) {
        printf("FOUND: %d\n", key);
        which = LEFT_NODE;
    } else if(s < key) { // adjust t1 pointer
        which = LEFT_NODE;
    } else
        which = RIGHT_NODE;
    return which;
}

void traverse(node *t1, node *t2, int key, int& which) {

    if(t1 == 0 || t2 == 0)
        return;

    printf("l: %d; r: %d\n", t1->val, t2->val);

    bool do_recurs = true;
    if(t1->left == 0 && t2->right == 0) { // traversal done!

        if(t1 == t2) {// need special processing..
            printf("error same node..\n"); // stop search
        }
            
        which = check(t1, t2, key);
        do_recurs = false;
    }

    node *s1 = t1, *s2 = t2;
    bool has_left = (s1->left != 0),
        has_right = (s2->right != 0);
    
    if(has_left)
        s1 = s1->left;
    if(has_right)
        s2 = s2->right;

    if(do_recurs)
        traverse(s1, s2, key, which);

    if(which == LEFT_NODE) { // need successor of t1 node
        if(has_left) { // t1 has left child
            which = check(t1, s2, key);
        } else {
//             printf("moving left node\n");
            // need to find in-order successor of 't1'
            traverse(t1->right, s2, key, which);
        }
    } else {
        if(has_right) { // t1 has left child
            which = check(s1, t2, key);
        } else {
            // need to find in-order predecessor of 't2'
            traverse(s1, t2->left, key, which);
        }
    }
}

void print_inorder_num(node *x) {
 
    if(x == 0)
        return;
    
    print_inorder_num(x->left);
    printf("node %d; isum: %d\n", x->val, x->sum);
    print_inorder_num(x->right);
}

// returns # nodes in a subtree
int inorder_sum(node *x, int right_sum) {

    if(x == 0)
        return 0;
    int tmp = inorder_sum(x->right, right_sum);
    
    x->sum = tmp + 1 + right_sum;

    tmp += inorder_sum(x->left, x->sum);

    return tmp + 1;
}



int main(){

    node *x, *y;
    node *head = append(0, 0, 15);
    node *l = append(head, 0, 7),
         *r = append(head, 1, 25);
         
    x = append(l, 0, 2);
    x = append(x, 1, 5);
    
    y = append(l, 1, 10);
    y = append(y, 0, 8);
         
    x = append(r, 0, 23);
    x = append(r, 1, 30);
    
    x = append(x, 0, 26);
    
    inorder_sum(head, 0);
    
    print_inorder_num(head);
    
    destroy_tree(head);
}

// int main() {
//     int a[] = {5,1,6,1,1,7};
//     int n = sizeof(a) / sizeof(int);
// 
//     min_3_numbers(a, n);
// }

