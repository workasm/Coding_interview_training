
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <map>
#include <stack>

// #include <math.h>
#include <stdio.h>

// inorder / preorder binary tree iterators

struct node {
    int val;
    node *left,*right;
    node(int v):val(v),left(0),right(0) {}
};

class Inorder_iterator {
private:
    std::stack<node *> s;
public:
    Inorder_iterator(node *rt) {
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

class Preorder_iterator {
private:
    std::stack<node *> s;
public:
    Preorder_iterator(node *rt) {
        if(rt != NULL)
            s.push(rt);
    }
    bool has_next() {
        return !s.empty();
    }
    node *next() {
        if(s.empty())
            return NULL;
        
        node *c = s.top(),
             *l = c->left, *r = c->right;
        s.pop();
        if(r)
            s.push(r);
        if(l)
            s.push(l);
             
        return c;
    }
};

bool same_inorder(node *a,node *b) {
    Inorder_iterator ita(a),itb(b);
    while (ita.has_next()&&itb.has_next()) {
        node *ca=ita.next();
        node *cb=itb.next();
        if (ca->val!=cb->val)
            return false;
    }
    return !ita.has_next()&&!itb.has_next();
}

node *append(node *parent, int which, int val) {

    node *x = new node(val);
    x->left = x->right = 0;

    if(parent != 0) {
        if(which == 0) 
            parent->left = x;
        else
            parent->right = x;
    }
    return x;
}

void print_inorder(node *root) {
 
    if(root == NULL)
        return;
    
    print_inorder(root->left);
    printf("%d ", root->val);
    print_inorder(root->right);
}

void print_preorder(node *root) {
 
    if(root == NULL)
        return;
    
    printf("%d ", root->val);
    print_preorder(root->left);
    print_preorder(root->right);
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

    printf("inorder: ");
    print_inorder(head);
    
    printf("\nInorder_iterator: ");
    Inorder_iterator ita(head);
    while (ita.has_next()) {
        node *ca=ita.next();
        printf("%d ", ca->val);
    }
    printf("\n");
    
    printf("\npreorder: ");
    print_preorder(head);
    
    printf("\nPreorder_iterator: ");
    Preorder_iterator itb(head);
    int ccc = 0;
    while (itb.has_next() && ccc++ < 100) {
        node *ca=itb.next();
        printf("%d ", ca->val);
    }
    printf("\n");
    
    destroy_tree(head);
}

