
#include <stdio.h>

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }

struct node {
    int val;
    node *left;
    node *right;
};

int A[20][20]; // A[i][j] stores sum of path from level i to level j

int sum;

// j is the current level
void traverse(node *t, int j) {

    if(t == 0)
        return;
    
    if(t->val == sum)
        printf("%d\n", sum);
    A[j][j] = t->val;

    for(int i = 0; i < j; i++) {
        A[i][j] = A[i][j-1] + t->val;
        
        if(A[i][j] == sum) {
            for(int k = j; k >= i; k--) {
                int tmp = A[i][k];
                if(k > i)
                    tmp -= A[i][k-1];
                printf("%d ", tmp);
            }
            printf("\n");
        } 
    }
    traverse(t->left, j+1);
    traverse(t->right, j+1);
}

// LCA of two nodes
node *LCA_in_btree(node *t, node *x, node *y) {

    if(t == 0)
        return 0;
    if(t == x || t == y)
        return t;

    node *t1 = LCA_in_btree(t->left, x, y);
    node *t2 = LCA_in_btree(t->right, x, y);

    if(t1 != 0 && t2 != 0)
        return t;
    if(t1 != 0)
        return t1;
    return t2;
}

node *append(node *parent, int which, int val) {

    node *x = new node;
    x->left = x->right = 0;
    x->val = val;

    if(parent != 0) {
        if(which == 0) 
            parent->left = x;
        else
            parent->right = x;
    }
    return x;
}

void destroy_tree(node *root) {

    if(root == 0)
        return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    delete root;
}

int main(){

    node *x, *y;
    node *head = append(0, 0, 10);
    node *l = append(head, 0, 5),
         *r = append(head, 1, 25),
         *ll = append(l, 0, 3),
         *lr = append(l, 1, 7);
    
    x = append(ll, 0, 2);
    append(ll, 1, 4);
    append(lr, 0, 6);
    append(lr, 1, 9);

    node *rl = append(r, 0, 15),
         *rr = append(r, 1, 30);

    x = append(rl, 0, 12);
    append(rl, 1, 24);
    append(rr, 0, 27);
    y = append(rr, 1, 35);

    sum = 40;
    node *t = LCA_in_btree(head, x, y);
    printf("lca of %d %d  is %d\n", x->val, y->val, t->val);
    
//     traverse(head, 0);  
    destroy_tree(head);
}
