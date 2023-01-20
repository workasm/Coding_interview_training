
print all nodes in a BST which are distance 'k' from a given node
(the distance can be counter upwards and downwards)

node *given;
int k;

print_k_dist_downwards(node *t, int lvl) {

    if(t == 0)
        return;

    if(lvl == 0) {
        printf(t);
    } else {
        print_k_dist_downwards(t->left, lvl-1);
        print_k_dist_downwards(t->right, lvl-1);
    }
}


print_k_dist_downwards(given, k);

bool print_k_dist_upwards(node *t, bool& cnt) {

    if(t == 0)
        return false;
    if(t == given) {
        cnt = k; // start countdown
        return true;
    }

    bool found = print_k_dist_downwards(t->left, cnt);
    if(!found) {
        found = print_k_dist_downwards(t->right, cnt);
    }

    if(!found)
        return false;

    if(cnt == 0) {
        print(t);   // found the node
    } 
    cnt--;  // decrement counter
    return true;
}

print_k_dist_upwards(root, cnt);
