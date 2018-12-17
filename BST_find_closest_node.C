

std::hast_set< int, int > vsums; // the hash containing vertical sums

void compute_vsums(node *t, int n) {
    if(t == 0)
        return;
    // one turn to the left corresponds to n-1
    // turn to the right corresponds to n+1
    vsums[n] += t->val;
    compute_vsums(t->left, n-1);
    compute_vsums(t->right, n+1);
}
call compute_vsums(root, 0);



node *closest_node;
double diff;


node *traverse(node *t, key) {

    if(t == 0)
        return;

    if(abs(t->value-key) < diff) {
        closest_node = t;
        diff = abs(t->value-key);
    }
    
    if(key < t->value) {
        traverse(t->left);
    } else {
        traverse(t->right);
    }
}

main() {

    diff = +infty;
    
    traverse(root, key);
    if(key-min < max-key)
        return min;
    else
        return max;
}