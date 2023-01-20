

#include <stdio.h>

struct node {
    node(int _v) : val(_v), next(0), prev(0) {}
    int val;
    node *next;
    node *prev;
};

void reverse_SLL(node **head) {
    
    if(!head)
        return;
    
    node *x = *head, *prev = 0, *y;
    while(x != 0) {
        y = x->next;
        x->next = prev;
        prev = x;
        x = y;
    }
    *head = prev;
}

void append(node **head, int v) {
 
    if(*head == 0) {
        *head = new node(v);
        return;
    }
    node *last = *head;
    while(last->next != 0) {
        last = last->next;
    }
    node *x = new node(v);
    last->next = x;
}

void print(node *x) {
    printf("\nlist: {");
    while(x) {
        printf("%d ", x->val);
        x = x->next;
    }
    printf("}\n");
}

void dellist(node *x) {
    node *next;
    while(x) {
        next = x->next;
        delete x;
        x = next;
    }
}

int main() {

    node *head = 0;
    int i;
    for(i = 0; i < 10; i++) {
        append(&head, i);
    }
    print(head);
    
    reverse_SLL(&head);
    print(head);
    
    dellist(head);
    return 1;
}