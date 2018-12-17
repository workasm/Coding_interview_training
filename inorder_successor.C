
#include <stdio.h>

struct node {
    node *left;
    node *right;
    node *parent;
};


node *inorder_next(node *t) {

    if(t == 0)
        return 0;
    if(t->right) {
        t = t->right;
        while(t->left != 0)
            t = t->left;
        return t;
    } 
    
    node *p = t->parent;
    while(p != 0 && p->right == t) {
        t = p;
        p = p->parent;
    }
    return p;
}

// set t->next pointers to node's inorder successor
void fill_inorder_succ(node *t, node *remote_parent) {

    if(t == 0)
        return 0;
    if(t->right != 0) {
        t->next = leftmost_child(t->right);
        find_inorder_suff(t->right, remote_parent);
    } else
        t->next = remote_parent;
    fill_inorder_succ(t->left, t);
}
fill_inorder_succ(root, 0);


node *wanted; // the node whose successor we wish to find
node *find_recurs(node *t, bool& found) {

    if(t == 0) {
        found = false;
        return 0;
    }
    if(t == wanted) {   // found the 'wanted' node
        found = true;   // in the traversal
        return 0;
    }
    node *x = find_recurs(t->left, found);
    if(found) {
        if(x != 0)
            return x; // the successor already found: just pass it by
        return t; // this is a successor
    }
    return find_rec(t->right, found);
}

node *inorder_succ() {
    if(wanted->right) {
        ... // proceed as in the above soln
        return t;
    }
    bool found = false; // otherwise start the search from the root
    return find_rec(root, found);
}
