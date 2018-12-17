
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>

#include <math.h>
#include <stdio.h>

//! find a point for which sum of distances to other points
//! is minimum

struct Point {
    Point() { }
    Point(int _x, int _y): x(_x), y(_y) { }
    int x, y;
};

int dist(const Point& p1, const Point& p2) {
   int dx = p1.x - p2.x, dy = p1.y - p2.y;
   return (dx*dx + dy*dy);
}

void min_point_dist(Point *pts, int n_pts) {

    int i, j, pt = -1, mind = 0;
   
    for(i = 0; i < n_pts; i++) {
        printf("(%d %d) ", pts[i].x, pts[i].y);
        int dst = 0;
        for(j = 0; j < n_pts; j++) {
            if(j != i)
                dst += dist(pts[i], pts[j]);
        }
        if(pt == -1 || dst < mind) {
            pt = i, mind = dst;
        }
    }
    printf("\npoint: (%d; %d) mind: %d\n", pts[pt].x,
            pts[pt].y, mind);

    float sx = 0, sy = 0;
    for(i = 0; i < n_pts; i++) {
        sx += pts[i].x, sy += pts[i].y;
    }
    sx /= n_pts, sy /= n_pts;
    printf("centroid: (%.3f; %.3f)\n", sx, sy);

    float mind2 = 0;
    int pt2 = -1;
    for(i = 0; i < n_pts; i++) {
        float dx = (sx - (float)pts[i].x),
              dy = (sy - (float)pts[i].y);
        float d = dx*dx + dy*dy;
        if(pt2 == -1 || d < mind2) {
            pt2 = i, mind2 = d;
        }
    }

    int dst = 0;
    for(j = 0; j < n_pts; j++) {
        dst += dist(pts[pt2], pts[j]);
    }
    
    printf("closest point: (%d; %d) %d\n", pts[pt2].x, pts[pt2].y,
           dst);
    
    if(pt != pt2 && dst > mind) {
        printf("FATAL: wrong!!\n");
        throw -1;
    }
}


int main() {

    srand48(time(NULL));
    int n = 100;
    Point *a = new Point[n];

    while(1) {
    for(int i = 0; i < n; i++) {
        a[i].x = lrand48() % 10;
        a[i].y = a[i].x*a[i].x-1 - lrand48() % 10;
    }
/*
    Point a[] = {Point(1,1), Point(2,4),
        Point(4,3), Point(-1,5), Point(5,1), Point(6,4)};
    int n = sizeof(a) / sizeof(Point);*/
    min_point_dist(a, n);
    }
    delete []a;
    return 1;
}




