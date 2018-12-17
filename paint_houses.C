
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


const int n_houses = 6;

int houses[n_houses][3] = {{7,5,10}, {3,6,1}, {8,7,4},
    {6,2,9}, {1,4,7}, {2,3,6}};

int cost[n_houses][3];

void paint_cost() {

    cost[0][0] = houses[0][0];
    cost[0][1] = houses[0][1];
    cost[0][2] = houses[0][2];

    for(int i = 1; i < n_houses; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", houses[i][j]);
            cost[i][j] = houses[i][j] + std::min(cost[i-1][(j+1)%3], cost[i-1][(j+2)%3]);
        }
        printf("\n");
    }

    printf("%d %d %d\n", cost[n_houses-1][0],cost[n_houses-1][1],cost[n_houses-1][2]);
}

int main() {

    paint_cost();
    return 1;
}

