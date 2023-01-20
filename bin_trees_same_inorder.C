


struct node {
    int val;
    node *left,*right;
    node(int v):val(v),left(0),right(0) {}
};

class bst_iterator {
private:
    stack<node *> s;
public:
    bst_iterator(node *rt) {
        while (rt)
            s.push(rt),rt=rt->left;
    }
    bool has_next() {
        return !s.empty();
    }
    node *next() {
        node *c=s.top();
        s.pop();
        node *n=c->right;
        while (n)
            s.push(n),n=n->left;
        return c;
    }
};

bool same_inorder(node *a,node *b) {
    bst_iterator ita(a),itb(b);
    while (ita.has_next()&&itb.has_next()) {
        node *ca=ita.next();
        node *cb=itb.next();
        if (ca->val!=cb->val)
            return false;
    }
    return !ita.has_next()&&!itb.has_next();
}