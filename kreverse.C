
#include <stdio.h>

list *kreverse(list *head, int k) {

    if(k <= 1) // nothing to reverse
        return head;
    
    list *p = head, *tail = 0;
    while(p != 0) {
        // remember where we start this piece
        list *start = p, *prev = 0, *temp; 
        int c = k;
        
        while(p != 0 && c-- > 0) { // do usual reverse
            temp = p->next;
            p->next = prev; 
            prev = p;   
            p = temp;
        }
        if(tail != 0)  // link reversed pieces 
            tail->next = prev;
        else // indicates the first piece   
            head = prev;
        tail = start;
        // here p points to the next part being processed
    }
    return head;
}