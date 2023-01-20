
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <map>


/** Given a Binary search tree of integer values. return the count of nodes where all the nodes under that sub-tree lies between a given range [x, y]. assume there are more than 100,000 nodes */


struct node {
    int val;        // BST value
    int sum;        // # of inorder successors
    node *left;     // children
    node *right;
};

node *xleft = 0, *xright = 0;

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


void print_inorder_num(node *x) {
 
    if(x == 0)
        return;
    
    print_inorder_num(x->left);
    printf("node %d; isum: %d\n", x->val, x->sum);
    print_inorder_num(x->right);
}

// returns # nodes in a subtree
//! for each node compute the number of inorder successors in the tree
int inorder_sum(node *x, int right_sum) {

    if(x == 0)
        return 0;
    int tmp = inorder_sum(x->right, right_sum);
   
    x->sum = tmp + 1 + right_sum;

    tmp += inorder_sum(x->left, x->sum);
    return tmp + 1;
}

void find_subtree(node *x, int vmin, int vmax) {

    if(x == 0)
        return;
    
    if(vmin <= x->val && x->val <= vmax) {
        // we know that this node lies within the interval =>
        // could improve the bounds if needed
        if(xleft == 0 || xleft->val > x->val)
            xleft = x;
            
        if(xright == 0 || xright->val < x->val)
            xright = x;
        
        find_subtree(x->left, vmin, x->val);
        find_subtree(x->right, x->val, vmax);
        
    } else if(x->val > vmax) { // no need to explore right subtree
        
        find_subtree(x->left, vmin, vmax);
    
    } else { // x->val < vmin => no need to expolore left subtree
        find_subtree(x->right, vmin, vmax);
    }
}
// once we have it, compute: xright->sum - xleft->sum + 1 => number
// of nodes in a subtrees


int main(){

    node *x, *y;
    node *head = append(0, 0, 15);
    node *l = append(head, LEFT_NODE, 7),
         *r = append(head, RIGHT_NODE, 25);
         
    x = append(l, 0, 2);
    x = append(x, 1, 5);
    
    y = append(l, 1, 10);
    y = append(y, 0, 8);
         
    x = append(r, 0, 23);
    x = append(r, 1, 30);
    
    x = append(x, 0, 26);
    
    inorder_sum(head, 0);
    
    int ll = 7, rr = 22;
    find_subtree(head, ll, rr);
    
    if(xleft != 0 && xright != 0) {
        printf("xleft: %d\n", xleft->val);
        printf("xright: %d\n", xright->val);
    
        printf("# of nodes in[%d; %d]: %d\n", ll, rr, 
               xleft->sum - xright->sum + 1);
    }
    
    print_inorder_num(head);
    
    destroy_tree(head);
}
