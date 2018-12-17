
#include <stdio.h>
#include <memory.h>
#include <string.h>

#define rows 4
#define cols 4

void find(int A[rows][cols], int x) {

    int i = rows - 1, j = 0;
    while(1) {
        printf("(%d;%d) ", i, j);
        
        if(A[i][j] == x) {
            printf("found at: (%d;%d)\n", i, j);
            return;
        }

// can you spead up using bin search over rows ?
        if(A[i][j] < x)
            j++; // go right
        else
            i--; // go left
        if(i < 0 || j >= cols)
            break;
    }
    printf("not found\n");
}

int main() {

    int A[][cols] = {{1, 1, 1, 1},
                    {1, 1, 1, 2},
                    {1, 1, 1, 3},
                    {1, 1, 1, 4}};

    find(A, 2);

    return 1;
}


