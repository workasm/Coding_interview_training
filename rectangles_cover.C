
#include <stdio.h>
#include <stack>
#include <memory.h>

#define rows 32
#define cols 32

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }
/*
 int input[rows][cols] = {
     {1,1,1,1,0,1,1,1,0,1,1},
     {1,1,1,1,1,1,0,1,0,1,0},
     {1,0,1,1,1,1,1,1,1,0,1},
     {1,1,1,1,1,1,1,1,1,1,1},
     {1,1,0,0,1,1,1,1,1,1,1},
     {1,1,1,1,1,0,1,1,1,1,1}
 };*/


int mm[rows] = {
    0xffffffff, 0xffffffff, 0xdeadbeef, 0xffff33ff,
                    
    0xdeadbeef, 0xffffffff, 0xffffffff, 0xdeadbeef,
    
    0xffffffff, 0xdeadbeef, 0xffffffff, 0xffffffff,
    
    0xffffffff, 0xffffefff, 0xffffffff, 0xffffffff,
    
    0xffffffff, 0xffffffff, 0xdeadbeef, 0xdeadbeef,
    
    0xdeadbeef, 0xffffffff, 0xffffffff, 0xffffffff,
    
    0xffffffff, 0xdeadbeef, 0xffffffff, 0xdeadbeef,
    
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffbbff };


typedef std::pair< int, int > Int_pair;

void print_matrix(int A[rows]) {
    int i,j;
    printf("\n--------------------------\n");
    for(i = 0; i < rows; i++) {
        printf("{ ");
        for(j = 0; j < cols; j++) {
            int b = (A[i] & (1 << j)) != 0;
            printf("%d,", b);
        }
        printf(" },\n");
    }
    printf("--------------------------\n");
}

#define XH_STACK_SIZE 33

typedef struct _XH {
    int x, h;
} XH;

XH g_xh_stack[XH_STACK_SIZE];
int g_xh_top = -1;

int stack_empty() {
   return (g_xh_top == -1);
}

void stack_push(int x, int h) {
    g_xh_top++;
    if(g_xh_top >= XH_STACK_SIZE) {
        printf("FATAL: stack is full!\n");
        return;
    }
    XH *pxh = g_xh_stack + g_xh_top;
    pxh->x = x, pxh->h = h;
}

void stack_top(int *x, int *h) {
    if(stack_empty()) {
        printf("FATAL: stack is empty!\n");
        return;
    }
    XH *pxh = g_xh_stack + g_xh_top;
    *x = pxh->x, *h = pxh->h;
}

void stack_pop() {
    if(!stack_empty()) 
        g_xh_top--;
}

void stack_reset() {
    g_xh_top = -1;
}

int sx=0, sy=0, w=0, h=0;

void largest_square(int A[rows]) {
    
    int c[cols];
    memset(c, 0, cols * sizeof(int));
    
    int x, y, x0, xx, hx;
    // best rect found so far:

    for(y = rows-1; y >= 0; y--) {
//         printf("y: %d -----------------------------------\n", y);
        
        int height = 0;
        stack_reset();
        for(x = 0; x < cols; x++) { // width: current with of this rectangle
            c[x] = (A[y] & (1 << x)) ? c[x]+1 : 0;

//             printf("%d: new height is: %d\n", x, c[x]);
            if(c[x] > height) {
                height = c[x];
//                 printf("pushed (%d; %d)\n", x, height);
                stack_push(x, height);
            }
            else if(c[x] < height) { // got lower boundary: pop all elems
                while(!stack_empty()) {
                    
                    stack_top(&xx, &hx);
//                     printf("top x0 = %d; h0 = %d\n", x0, h0);
                    
                    if(hx <= c[x]) // do not pop all further rects
                        break;
                    x0 = xx;
//                     printf("checking rect: (%d; %d) - (%d; %d)\n", 
//                             x0, y, x-x0, h0);
                    
                    stack_pop();
                    if(hx*(x-x0) > w*h) {
                         sx = x0, sy = y;
                         w = x-x0, h = hx;
                    }
                }
                height = c[x];
                if(height != 0) {
//                     printf("pushed back (%d; %d)\n", x0, height);
                    stack_push(x0, height);
                }
            }
        }
        
        while(!stack_empty()) {
            stack_top(&xx, &hx);
            stack_pop();
            if(hx * (x - xx) > w*h) {
                sx = xx, sy = y;
                w = x-xx, h = hx;
            }
        }
    }
    
    printf("max: (%d;%d) - (%d;%d)\n", sx,sy, w,h);

}

int main() {

    int i, j, k;
    int prevw = 0, prevh = 0;
    
    for(k = 0; k < 32; k++) {
        print_matrix(mm);

        prevw = w, prevh = h;
        sx=0,sy=0,w=0,h=0;
        largest_square(mm);
        
        if(k != 0 && prevw*prevh < w*h) {
            printf("%d: FATAL: wrong square found !!\n", k);
            break;
        }
    
        unsigned mask = 0xFFFFFFFFU;
        if(w < 32) 
            mask = ((1 << w) - 1) << sx;
        
        for(i = sy; i < sy + h; i++) {
            if((mm[i] & mask) != mask) {
                printf("%d: FATAL: wrong square found!!\n", sy);
                return 1;
            }
                
            mm[i] &= ~mask;
//             for(j = sx; j < sx + w; j++) {
//                 input[i][j] = 0;
//             }
        }
    }
    print_matrix(mm);

    //check against the original matrix that no wrong elements 

    return 1;
}

