
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>
#include <stdio.h>

#define rows 5
#define cols 8

struct Sub_m {  // submatrix
    Sub_m() : w(1), h(1) { }

    std::vector< int > w, h;
};

// h[] - heights of histogram bars
void max_0x_submatrix(int a[rows][cols]) {

    Sub_m S[rows][cols];

    int si, sj, maxw = 0, maxh = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {

            Sub_m& s =  S[i][j];
            if(a[i][j] == 1) { // empty cell
                s.w[0] = 0, s.h[0] = 0;
                continue;
            }

            if(i == 0) { // first row
                s.w[0] = (j == 0 ? 0 : S[i][j-1].w[0]) + 1;
                s.h[0] = 1;
                continue;
            } else if(j == 0) { // first column
                s.w[0] = 1;
                s.h[0] = S[i-1][j].h[0] + 1;
                continue;
            }
            // general case
            Sub_m& s1 = S[i][j-1], s2 = S[i-1][j];

            int niters = 0;
            int w = 0, h = 0;
            for(int i1 = 0; i1 < s1.w.size(); i1++) {
                for(int i2 = 0; i2 < s2.w.size(); i2++) {

                    int w1 = s1.w[i1] + 1, h1 = std::min(s1.h[i1],
                        s2.h[i1] + 1);
                    int w2 = std::min(s2.w[i2], s1.w[i2] + 1),
                        h2 = s2.h[i2] + 1;

                printf("(%d; %d): (%d %d), (%d %d)\n", i, j, w1, h1, w2, h2);

                    if(w1*h1 >= w2*h2 && w1*h1 >= w*h && w1*h1 != 0) {
                        if(w1*h1 != w*h) {
                            s.w.clear(); s.h.clear();
                            printf("cleared\n");
                        }
                        s.w.push_back(w1);
                        s.h.push_back(h1);
                        w = w1, h = h1;
                        printf("pushed\n");
                    }

                    if(w2*h2 >= w1*h1 && w2*h2 >= w*h && w2*h2 != 0) {
                        if(w2*h2 != w*h) {
                            s.w.clear(); s.h.clear();
                            printf("cleared\n");
                        }
                        s.w.push_back(w2);
                        s.h.push_back(h2);
                        w = w2, h = h2;
                        printf("pushed\n");
                    }
                    niters++;
                }
            }

            printf("niters: %d; size: %d\n", niters, s.w.size());
            printf("(%d; %d): w: %d; h: %d\n", i, j, s.w[0], s.h[0]);
            
//             if(maxw*maxh < s.w*s.h) {
//                 si = i, sj = j;
//                 maxw = s.w, maxh = s.h;
//             }
        }
    }
//     printf("(%d; %d): maxw: %d; maxh: %d\n", si, sj, maxw, maxh);
}

int main() {
     int a[rows][cols] = {
        {1, 0, 1, 0, 0, 1, 1, 0 },
        {1, 0, 0, 0, 0, 0, 1, 1 },
        {1, 1, 0, 0, 0, 0, 1, 0 },
        {1, 0, 1, 0, 0, 0, 1, 1 },
        {1, 0, 0, 1, 0, 0, 1, 0 }
    };

    max_0x_submatrix(a);

}


