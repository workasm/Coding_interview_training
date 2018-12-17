
char pre_order[];
int sz = sizeof(pre_order);
stack<node *> S;

note *root, *parent = 0;
for(int idx = 0; idx < sz; idx++) {
    node *t = new node;
    t->left = t->right = 0;
    if(parent != 0) {
        if(parent->left == 0)
            parent->left = t;
        else
            parent->right = t;
    } else {
        root = t;
    }
    if(pre_order[idx] == 'N') {
        parent = t;
        S.push(t);
    } else if(!S.empty()) 
        parent = S.pop();
    }
}

