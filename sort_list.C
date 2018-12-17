
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct List {

    List *next;
    int x;
};

void print_list(List *head) {

    printf("dumping the list: [");
    while(head) {
        printf("%d ", head->x);
        head = head->next;
    }
    printf("]\n\n");
}

List *sort_list(List *head) {

    if(head == NULL)
        return head;

    List *prevc = head, *curr = head->next;
    while(curr != NULL) {
    
        List *prev = 0, *p = head;
        while(p != curr) {
            if(p->x < curr->x) {
                prev = p;
                p = p->next;
            } else
                break;
        }
        if(p != curr) { // need to swap
            prevc->next = curr->next; // remove curr
            curr->next = p; // insert curr before p
            if(prev == 0)  // changing the head
                head = curr;
            else 
                prev->next = curr;
            // point to the next element to process
            curr = prevc->next; // prevc stays unchanged
        } else {
            prevc = curr;
            curr = curr->next;
        }    
    }
    return head;
}

int main() {

    int n = 211;

    srand(time(NULL));
    List *head = new List;
    head->x = rand() % 1;
    
    List *ptr = head;
    for(int i = 0; i < n-1; i++) {
        
        ptr->next = new List;
        ptr = ptr->next;
        ptr->x = rand() % 1;
    }
    ptr->next = 0;
    print_list(head);

    head = sort_list(head);
    print_list(head);

    printf("x = %d", (-26 % 16));
    
    return 0;
}


