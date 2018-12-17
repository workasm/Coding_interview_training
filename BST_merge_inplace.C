
node *root = 0;

merge(node *t1, node *t2) {

    if(t1 == 0) {

        || t2 == 0)
        return;

    // t1 always becomes a root
    if(t1->val < t2->val) {
        tmp = t1->right;
        t1->right = t2;
        merge(t1->left, t2->left);
        merge(tmp, t2->right);
    } else {
        tmp = t1->left;
        t1->left = t2;
        merge(tmp, t2->left);
        merge(t1->right, t2->right);
    }
}


