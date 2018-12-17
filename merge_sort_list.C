
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

// merge sort: returns a pointer to the head of a sorted list
list *merge_sort(list *head) {

    if(head == 0)
        return 0;

    list *p = head, *pp = p, *prev = 0
    if(p->next == 0)
        return head; // already sorted

    // find a split in the middle using two ptrs
    while(pp != 0 && pp->next != 0) {
        prev = p, p = p->next;
        pp = pp->next->next;
    }
    prev->next = 0; // cut the list in the middle
    list *h1 = merge_sort(p),
         *h2 = merge_sort(head);   // sort the two parts

    head = h1, prev = 0;
    // merge the list 'h2' into 'h1' inplace
    while(h2 != 0) {
        if(h1 != 0 && h2->val >= h1->val) {
            prev = h1;      // just iterater through 'h1' list
            h1 = h1->next;
        } else { // insert 'h2' before 'h1'
            list *t = h2->next; // save the 'next' pointer
            if(prev == 0) { // insert a new head
                h2->next = head;
                head = h2;
            } else {
                prev->next = h2;
                h2->next = h1;
            }
            prev = h2; h2 = t;
        }
    }
    return head;
}

/*
// partition an array in such a that left part < a[p] and right part > a[p]
partition(int *a, int l, int r, int p) {

    pivot = a[p];
    swap(a[p], a[r]);
    
    int store_i = l; 
    for(i = l; i < r; i++) {
        if(a[i] < pivot) {
            swap(a[i], a[store_i]);
            store_i++;
        }
    }
    swap(a[r], a[store_i]);
}
*/

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

    head = merge_sort(head);
    print_list(head);

    printf("x = %d", (-26 % 16));
    
    return 0;
}


