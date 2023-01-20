

add_leaf_to_list(node *t) {
// make a linked list out of nodes 't'
}

reverse_tree(node *t) {

    if(t == 0)
        return;

    for(i = 0; i < t->nchildren; i++) {
        reverse_tree(t->child[i]);
        t->child[i]->child[0] = t;
        t->child[i]->nchildren = 1;
    }
    if(t->nchildren == 0) 
        add_leaf_to_list(t);

    s = reverse_tree(t->right); 
    if(s != 0)
        s->left = t;

    s = reverse_tree(t->left);
    if(s != 0)
        s->left = t;
    if(t->left == 0 && t->left == 0)
        add_leaf(t);
    return t;
}


A[k] = {1,3,4,7,10};

idx2find = {1,2,3,4,5};
for(i = 1; i <= n; i++) {
    
    if(A.find(i) == 0) {
        idx2find--;
    }
    if(idx2find == 0)
        break;
}
