
#include <stdio.h>

std::hash_set<int> processed;

struct node {
    int data;
    x *p1;
    x *p2;
};

node *deep_copy(node *x) {
    
    if(x == 0)
        return 0;
    // found a loop
    if(processed.find((int&)x) != processed.end())
        return x;  
    
    processed.insert((int&)x); // mark x as already processed   
    node *p = new node;
    p->data = x->data;
    p->p1 = deep_copy(x->p1);
    p->p2 = deep_copy(x->p2);
    return p;
}


main() {
    
    node *clone = deep_copy(x);

}

