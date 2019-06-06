

min_so_far = +infty
// two node stacks holding the current path and
// the min sum path found so far
stack< node > cur_path, min_path;

void min_sum(node *t, int sum) {

    cur_path.push(t);
    sum += t->val;
    if(t->left != 0) {
        min_sum(t->left, sum);
    }
    if(t->right != 0) {
        min_sum(t->right, sum);
    } else if(t->left == 0) { // we are in the leaf node: check the sum
        if(min_so_far > sum) {
            min_so_far = sum;
            min_path = cur_path;
        }
    }
    cur_path.pop(t);    
}

call min_sum(root, 0);