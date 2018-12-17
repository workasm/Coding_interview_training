

node *p1, *p2;
node *common = 0;

bool common_ancestor(node *t) {

    if(t == 0)
        return false;
    if(t == p1 || t == p2) // match found
        return true;

    bool hit1 = common_ancestor(t->left);
    if(common != 0) // already found
        return false;

    bool hit2 = common_ancestor(t->right);
    if(hit1 & hit2) {
        common = t;
        return false;
    }
    return (hit1 | hit2);
}

main() {

    // assign p1 and p2 to some leaf nodes
    common_ancestor(root);
}
