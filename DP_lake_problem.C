

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <iomanip>

#include <memory.h>
#include <stdio.h>

#define rows 5
#define cols 5
#define HEIGHTS 10

enum {LEFT = 0, RIGHT, DOWN, UP};

// int lake_x = 0, lake_y = 0;
// int dam_x = 3, dam_y = 2;

int lake_x = 0, lake_y = 0;
int dam_x = 2, dam_y = 2;

// int height[rows][cols] = {
//         {2,7,3,1,0},
//         {2,1,1,7,1},
//         {7,7,7,2,1}};

int height[rows][cols] = {
        {2,2,1,1,1},
        {9,9,9,7,1},
        {7,1,1,9,1},
        {7,1,7,9,1},
        {7,1,1,1,1}};

int DP[rows][cols][HEIGHTS]; // DP[i][j]: minimal cost to build a path
                // from (i;j) to (dam_x; dam_y)

bool visited[rows][cols];

int next[rows][cols][HEIGHTS];

int explore(int x, int y, int cur_h) {

    if(x < 0 || x >= cols || y < 0 || y >= rows)
        return 0x100000;

    if(visited[y][x])
        return 0x100000;

    visited[y][x] = true;
    
    if(DP[y][x][cur_h] != -1) {
        visited[y][x] = false;
        return DP[y][x][cur_h];
    }

    if(x == dam_x && y == dam_y) {
        visited[y][x] = false;
//         printf("found %d; %d; %d\n", x, y, cur_h);
        if(cur_h >= height[y][x])
            return 0;
        return std::abs(height[y][x] - cur_h); // compute cost for the excavation
    }

    // we have a point with required height cur_h
    // its original height is height[x][y]
    
    for(int h = 0; h <= cur_h; h++) {
        int c = explore(x - 1, y, h), c2, dir;
        dir = LEFT;

        c2 = explore(x, y - 1, h);
        if(c2 < c) {
            dir = DOWN, c = c2;
        }

        c2 = explore(x + 1, y, h);
        if(c2 < c) {
            dir = RIGHT, c = c2;
        }
        c2 = explore(x, y + 1, h);
        if(c2 < c) {
            dir = UP, c = c2;
        }
        c2 = DP[y][x][cur_h];
        c += std::abs(cur_h - height[y][x]);
        if(c2 == -1 || c2 > c) {
            next[y][x][cur_h] = (dir << 4) + h;
            DP[y][x][cur_h] = c;
        }
    }
    visited[y][x] = false;
    return DP[y][x][cur_h];
}

int main() {
    memset(DP, 0xff, rows*cols*HEIGHTS*sizeof(int));
    memset(visited, 0, rows*cols*sizeof(bool));
    memset(next, 0xff, rows*cols*HEIGHTS*sizeof(int));

    int lake_h = height[lake_y][lake_x];
    int cost = explore(lake_x, lake_y, lake_h);

    printf("mininmal cost: %d\n", cost);

    char path[rows][cols];
    memset(path, 'X', rows*cols);

    int x = lake_x, y = lake_y, h = lake_h;
    while(1) {
        path[y][x] = '*';
        if(x == dam_x && y == dam_y)
            break;
        
        int dir = next[y][x][h];
        h = dir & 0xf;
        dir >>= 4;
        
        switch(dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWN:
            y--;
            break;
        case UP:
            y++;
            break;
        default:
            printf("FATAL: wrong dir: %d\n", dir);
            exit(1);
        }
    }

    for(y = 0; y < rows; y++) {
        for(x = 0; x < cols; x++)
            printf("%c", path[y][x]);
        printf("\n");
    }
    return 0;
}

