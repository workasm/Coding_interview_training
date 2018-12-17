

//! Round2 | Q2 : Given A Binary Tree of size n , Find Out a Matrix M[n][n], where M[i][j]=1 if i is predecessor of j, else M[i][j]=0. [Hints DP]


int M[n][n];

build_matrix(node *t) {

    if(t == 0)
        return;

    int ID = t->ID; // get the ID of this node
    set M[ID][0..n-1] = 0; // clear out predecessor row for this node
    M[ID][ID] = 1; // a node is a predecessor of itself ??

    if(t->left != 0) {
        int lID = t->left->ID;
        M[ID][lID] = 1; // left and right children are successors
        build_matrix(t->left);
        // copy successors of left subtree
        for(i = 0; i < n; i++)
            M[ID][i] |= M[lID][i];
    }

    if(t->right != 0) {
        int rID = t->right->ID;
        M[ID][rID] = 1; // left and right children are successors
        build_matrix(t->right);
        // copy successors of right subtree
        for(i = 0; i < n; i++)
            M[ID][i] |= M[rID][i];
    }
}
