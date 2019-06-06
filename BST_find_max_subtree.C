
int max_so_far = 0;
// in each recursive call [low; up] specifies the valid range of node
// values to satisfy the BST property
int max_BST_subtree(node *t, int low, int up) {
    if(t == 0)      // found a leaf node
        return 0;
    // indicates that the BST property is broken
    if(t->val <= low || t->val >= up)
        return -1; 

    // count the number of nodes in a BST tree
    int s_left = max_BST_subtree(t->left, low, t->val);
    int s_right = max_BST_subtree(t->right, t->val, up);

    // take either left part, right part or both
    if(s_left != -1 && s_right != -1)
        s = s_left + s_right + 1; // take both subtrees + root node
    else
        s = max(s_left, s_right); // take on of subtrees

    max_so_far = max(s, max_so_far);
    return s; // return the number of nodes found (or -1 if no BST)
}
call max_BST_subtree(root, -infty, +infty);




sum_of_BST

compute_sum(node *t) {

    if(t == 0)
        return 0;
    t->val += compute_sum(t->left) +
            compute_sum(t->right);
    return t->val;

}