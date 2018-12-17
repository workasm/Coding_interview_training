
#include <stdio.h>

struct X {

int a;
union {
int b;
float xx[2];
};
int c;
};

#define OFS(struc, field) \
        (char *)(&((struc *)NULL)->field)

#define SIZEOF(x) \
        ((char *)(&(x)+1) - (char *)&(x))

#define SIZEOF_type(T) \
        ((char *)((typeof(T) *)0 + 1))

int main() {

    int xx;
    printf("%d\n", SIZEOF_type('c'));
    return 1;
}

#if 0
To traverse a non-empty binary tree in preorder, perform the following operations recursively at each node, starting with the root node:

   1. Visit the root.
   2. Traverse the left subtree.
   3. Traverse the right subtree.

(This is also called Depth-first traversal.)

To traverse a non-empty binary tree in inorder, perform the following operations recursively at each node, starting with the root node:

   1. Traverse the left subtree.
   2. Visit the root.
   3. Traverse the right subtree.

To traverse a non-empty binary tree in postorder, perform the following operations recursively at each node, starting with the root node:

   1. Traverse the left subtree.
   2. Traverse the right subtree.
   3. Visit the root.
#endif