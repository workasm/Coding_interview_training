


maintain a hash for each
node storing all partial
sums including this node

bool has_sum(node *t, hash h) {

    if(t == 0)
        return false;

    hash h_l, h_r;
    if(has_sum(t->left, h_l))
        return true;
    
    if(has_sum(t->right, h_r))
        return true;

    hash h
    if(t->value == sum)
        return true;
    h.add(t->value);
    
    forall x in h_l do
        x += t->value;
        if(x == sum)
            return true;
        h.add(x)
    }
    forall x in h_r do
        x += t->value;
        if(x == sum)
            return true;
        h.add(x)
    }
    return false; // no found yet
}



void tree_depth(node *root) {

    stack< node *> s;

    max_h = 0;
    s.push(root, 0);
    while(!s.empty()) {

        (t, h) = s.pop();
        if(t == 0)
            continue;
        h++;
        max_h = max(h, max_h);
        s.push(t->left, h);
        s.push(t->right, h);
    }
}

find_LCA(node *a, node *b) {

    need to compute depths of both nodes
}











