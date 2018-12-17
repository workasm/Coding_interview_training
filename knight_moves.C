
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>
#include <stdio.h>
#include <memory.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

const int board_sz = 8;
const int K = 3;

int alive[board_sz][board_sz][K];

double knight_alive(int r, int c, int k) {
    
        if (r < 0 || r >= board_sz || c < 0 || c >= board_sz)
            return 0.0;
        if (k == 0)
            return 1.0;
        // K is one based
        if (alive[r][c][k-1] != -1)
            return alive[r][c][k-1];
        double p = 0.0;
        p += knight_alive(r-2, c-1, k-1)/8;
        p += knight_alive(r-2, c+1, k-1)/8;
        p += knight_alive(r+2, c-1, k-1)/8;
        p += knight_alive(r+2, c+1, k-1)/8;
        p += knight_alive(r-1, c-2, k-1)/8;
        p += knight_alive(r+1, c-2, k-1)/8;
        p += knight_alive(r-1, c+2, k-1)/8;
        p += knight_alive(r+1, c+2, k-1)/8;
        alive[r][c][k-1] = p;
        return p;
}
    

int main() {

    memset(alive, 0xff, board_sz*board_sz*K*sizeof(int));

    int r = 3, c = 3;
    printf("%.3f \n", knight_alive(r, c, K));
    //paint_cost();
    return 1;
}

