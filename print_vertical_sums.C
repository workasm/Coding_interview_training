

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



// versioned stack:

node *head_list = 0;
static int version = 0;

std::vector< node * > ver;

void push(int val) {

    node *t = new node;
    t->val = val;
    t->next = head_list;
    head_list = t;
    ver.push_back(t);
    version++;
}

int pop() {
    node *t = head_list->next;
    ver.push_back(t);
    version++;

    int val = head_list->val;
    head_list = t;
    return val;
}

