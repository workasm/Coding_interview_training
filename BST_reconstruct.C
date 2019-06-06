

// A[n] - array containing preorder traversal of a BST
root = new node;
t = root;
t->parent = 0;
t->val = A[0];
split = t;

for(i = 1; i < n; i++) {
    if(A[i] < t->val) {
        add_left_child(t, A[i]);
        split = t;
        t = t->left;
        continue;
    } 
    // if split  == 0 or A[i] < split->val then just add to the right
    // child of the current node 't' otherwise find another 'split'
    if(split != 0 && A[i] > split->val) {
        t = split;
        while(t->parent != 0) {
            if(A[i] < t->parent->val)
                break;
            t = t->parent;
        }
        split = t;
    }
    add_right_child(t, A[i]);
    t = t->right;
}


// note sure if this algorithm is correct