
#include <stdio.h>

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }

struct node {
    int key;
    node *left;
    node *right;
    node *parent;
};

node *insert(node *root, int key) {

    node *x = root, *prev = 0;
    
    while(x != 0) {
        prev = x;
        if(key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    
    x = new node;
    x->key = key;
    x->left = x->right = 0;
    x->parent = prev;    

    if(prev == 0)
        root = x;
    else {
        if(key < prev->key)
            prev->left = x;
        else
            prev->right = x;
    }    
    return root;
}


node *succ(node *z) {
    
    if(z == 0)
        return 0;
    
    if(z->right != 0) { // find lowest ancestor
        z = z->right;
        while(z->left != 0)
            z = z->left;
        return z;
    } 
    
    node *p = z->parent;
    while(p != 0 && p->right == z) {
        z = p;
        p = p->parent;
    }
    return p;
}

node *remove(node *root, node *z) {

    if(z == 0)
        return root;

    node *del = z->right;
    if(del != 0 && z->left != 0) {
        // here z has both children: find it's inorder successor
        while(del->left != 0)
            del = del->left;
        z->key = del->key; // rewrite it's key
    } else
        del = z;

    // del points to the node to be removed
    node *p = del->parent, *child = del->left;
    if(child == 0)
        child = del->right;

    if(child != 0)
        child->parent = p;
    
    if(p != 0) {
        if(del == p->left) 
            p->left = child;
        else 
            p->right = child;
    } else  
        root = child;

    delete del;
    return root;
}


