
#include <stdio.h>

list *add_lists(list *a, list *b) {

    if(!a && !b)
        return 0;

    list head, *c = &head;
    int carry = 0;
    while(a != 0 || b != 0) {

        int na = 0, nb = 0;
        if(a != 0) {
            na = a->d; a = a->next;
        }
        if(b != 0) {
            nb = b->d; b = b->next;
        }
        int nc = na + nb;
        carry += (nc < na);
        nc += carry;
        carry = (nc < carry);
        
        c->next = new list;
        c = c->next;
        c->d = nc;
    }
    if(carry) {
        c->next = new list;
        c = c->next;
        c->d = carry;
    }
    c->next = 0;
    return head.next;
}


// rotate strings: concatenate with itself and do: ABCDABCD
// and do strstr()

int main() {

    get_it(3);
    return 1;
}