
// check whether a binary tree is symmetric: i.e., if it's a mirror of itself

bool symm_tree_check(node *l, node *r) {

    if(l == 0 && r == 0)
        return true;

    if((l != 0 && r == 0) || (l == 0 && r != 0))
        return false;

    return symm_tree_check(l->right, r->left) &&
        symm_tree_check(l->left, r->right);
}

symm_tree_check(root->left, root->right);