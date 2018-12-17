

// find a least common ancestor (LCA) of two nodes x and y in a BST

node *LCS_in_BST(node *t, int x, int y) {

    if(t == 0)
        return 0;

    if(x == t->val || t->val == y)
        return t;

    // 't' lies in between x and y
    if(x > t->val && t->val < y)
        return t;

    if(t->val < x) { // look in the right subtree
        return LCS_in_BST(t->right, x, y);
    }
    // y < t->val: look in the left subtree 
    return LCS_in_BST(t->left, x, y);
}


// LCA of two nodes in binary tree
node *LCA_in_btree(node *t, node *x, node *y) {

    if(t == 0)
        return 0;
    if(t == x || t == y)
        return t;

    node *t1 = LCA_in_btree(t->left, x, y);
    node *t2 = LCA_in_btree(t->right, x, y);

    if(t1 != 0 && t2 != 0)
        return t;
    if(t1 != 0)
        return t1;
    return t2;
}
