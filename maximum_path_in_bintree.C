


Given a binary tree, find 2 leaf nodes say X and Y such that F(X,Y) is maximum where F(X,Y) = sum of nodes in the path from root to X + sum of nodes in the path from root to Y - sum of nodes in the common path from root to first common ancestor of the Nodes X and Y


int max_so_far = -infty;
node *gX, *gY;
// function returns a pointer to the leaf node with
// maximum sum along some path from the root
node *find_max_Fxy(node *t, int common, int& max1) {

    if(t == 0)
        return 0;

    if(t->left == 0 && t->right == 0) { // found a leaf node
        max1 = t->val + common; // return sum to this leaf
        return t;
    }

    node *X = find_max_Fxy(t->left, t->val + common, f1);
    node *Y = find_max_Fxy(t->right, t->val + common, f2);

    if(X != 0 && Y != 0) {
        sum = f1 + f2 - common;
        if(max_so_far < sum) {
            max_so_far = sum;
            gX = X, gY = Y;
        }
    }

    if(Y == 0 || f1 > f2) {
        max1 = f1;
        return X;
    }
    max1 = f2;
    return Y;
}

find_max_Fxy(root, 0, max);
