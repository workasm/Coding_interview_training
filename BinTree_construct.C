
#include <stdio.h>

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }

struct node {
    int val;
    node *left;
    node *right;

    node() : left(0), right(0) { }
    node(int v) : val(v), left(0), right(0) { }
};


/**
node *construct(int *inorder, *int preorder, int sz) {

    if(sz == 0)
        return 0;

    int root = preorder[0];
    node *head = new node;

    int split = 0;
    while(root != inorder[split])
        split++;
    // split points to the root in inorder traversal
    head->left = construct(inorder, preorder + 1, split);
    head->right = construct(inorder + split + 1,
        preorder + split + 1, sz - split - 1);
    return head;
}
**/

// binary tree from preorder traversal

node *head;
int preorder[] = {20,1,19,2,18,3,17,4};
//{14,5,3,1,13,12,11,10,20,19,15,40};
//     {5,3,1,8,7,9};
    //{6,3,1,5,4};
int n = sizeof(preorder) / sizeof(int);

// i: index in the preorder traversal being processed
// max_right: maximal value for the right child of 'parent' in BST
// returns the last element used in the list
int construct(node *parent, int i, int max_right) {

    if(i >= n)
        return i;

    printf("parent->val = %d; i = %d; val[i] = %d; max_right: %d\n",
           parent->val, i, preorder[i], max_right);
    
    node *t;
    int val = preorder[i];
    if(val < parent->val) {
        t = new node(val);
        parent->left = t;
        i = construct(parent->left, i+1, parent->val);

        if(i >= n)
            return i;
        val = preorder[i];
    }
    if(val < max_right) {
        t = new node(val);
        parent->right = t;
        i = construct(parent->right, i+1, max_right);
    } 
    return i;
}

void destroy_tree(node *root) {

    if(root == 0)
        return;

    destroy_tree(root->left);
    printf("%d ", root->val);
    destroy_tree(root->right);
    delete root;
}

int main() {

    int val = preorder[0];
    head = new node(val);
    construct(head, 1, 1<<24);
    destroy_tree(head);
    printf("\n");
}
