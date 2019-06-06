
#include <stdio.h>

#define LEFT  0
#define RIGHT 1

struct node {
    int key;
    node *left;
    node *right;
};

// returns a pointer to the added node
node *add_node(node *x, int key, int LR) {

    if(x != 0) {
        if(LR == LEFT) {
            x->left = new node;
            x = x->left;
        } else {
            x->right = new node;
            x = x->right;
        }
    } else
        x = new node;

    x->key = key;
    x->left = 0;
    x->right = 0;
    return x;
}

// extend this to doubly-linked list

// this one needs a global variable to keep the list head
list *build_list(node *t, list *curr) {

    if(t == 0)
        return curr;
    curr = build_list(t->left, curr);
    curr->next = new list;
    curr = curr->next;
    curr->d = t->d;
    return build_list(t->right, curr);
}

//! builds a doubly-linked list from BST, returns
//! a pointer to the root
list *head = 0;  
build_DL_list(node *t, list *& last) {

    if(t == 0)
        return;

    build_list(t->left, last);

    list *cur = new node;
    if(last == 0) {
        head = cur;
        last = cur;
        cur->prev = 0;
    } else {
        last->next = cur;
        cur->prev = last;
    }
    build_list(t->right, last);
}

//! builds a doubly-linked list from BST, returns
//! a pointer to the root
list *build_DL_list(node *t, list *last) {

    if(t == 0)
        return last;

    // last is a most recently connected node
    last = build_list(t->right, last);

    list *cur = new node;
    cur->next = last;
    cur->data = t->data;
    if(last != 0)
        last->prev = cur;
    last = cur;

    return build_list(t->left, last);
}

// list: by connecting 'right' pointers of the tree
// this one returns the pointer to the list's head
// 'last' denotes the last connected node
node *build_list_inplace(node *t, node *last) {

    if(t->right != 0) {
        last = build_list_inplace(t->right, last);
    }
    t->right = last;
    last = t;

    if(t->left != 0) 
        last = build_list_inplace(t->left, last);

    return last;
}
// call build_list2(root, 0);

void print_BST(node *t) {

    if(t == 0)
        return;
    print_BST(t->right);
    printf("%d ", t->key);
    print_BST(t->left);
}

void delete_BST(node *t) {
    if(t == 0)
        return;
    delete_BST(t->right);
    delete_BST(t->left);
    delete t;
}

int main() {

    node *x, *root = add_node(0, 5, 0);

    x = add_node(root, 10, RIGHT);
    add_node(x, 6, LEFT);
    add_node(x, 11, RIGHT);

    print_BST(root);
    printf("\n");
    delete_BST(root);
    return 1;
}


