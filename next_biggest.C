


struct bin_tree {
    bin_tree *left;
    bin_tree *right;
    int n;
};


int next_biggest(bin_tree *t, int val) {

    if(t == 0)
        return -1;
    if(val < t->n) {
        c = next_biggest(t->left, val);
        if(c != -1)
            return c;
        return t->n;
    }
    return next_biggest(t->right, val);
}

