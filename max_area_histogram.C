
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

// find rectangle with the maximal area in a histogram

// h[] - heights of histogram bars
void max_area_hist(int *h, int n) {

    std::vector< int > s;
    std::vector< int > L(n), R(n); // how much each bar extends
                // to the left and to the right
    s.push_back(0); // first element pushed
    int max_i = 0;
    L[0] = -1;

    // go from left to right, populate 'L' array
//     for(int i = 1; i < n; i++) {
//         if(h[i] > h[max_i]) {
//             s.push_back(i);
//             L[i] = i;
//             max_i = i;
//         } else if(h[i] == h[max_i]) {
//             L[i] = max_i; // keep the one previously saved
//             s.push_back(i);
//         } else {
//             // remove all bars with height > h[i]
//             while(!s.empty()) {
//                 if(h[s.back()] >= h[i])
//                     s.pop_back();
//                 else
//                     break;
//             }
//             if(s.empty())
//                 L[i] = -1;
//             else
//                 L[i] = s.back();
//             s.push_back(i);
//             max_i = i;
//         }
//     }
// 
//     s.clear();
//     s.push_back(n-1); // last element pushed
//     R[n-1] = n;
//     max_i = n-1;
//     for(int i = n - 2; i >= 0; i--) {
//         if(h[i] > h[max_i]) {
//             s.push_back(i);
//             R[i] = i;
//             max_i = i;
//         } else if(h[i] == h[max_i]) {
//             R[i] = max_i; // keep the one previously saved
//             s.push_back(i);
//         } else {
//             // remove all bars with height > h[i]
//             printf("%d: h[i] < %d\n", i, h[max_i]);
//             while(!s.empty()) {
//                 if(h[s.back()] >= h[i]) {
//                     printf("%d: popping %d\n", i, s.back());
//                     s.pop_back();
//                 } else
//                     break;
//             }
//             if(s.empty())
//                 R[i] = n;
//             else
//                 R[i] = s.back();
//             s.push_back(i);
//             max_i = i;
//         }
//     }

    for(int i = 0; i < n; i++) {
        int area = (i - L[i]-1 + 1 + R[i] - i-1) * h[i];
        printf("bar: %d; L: %d; R: %d; area: %d\n", i,
                L[i], R[i], area);
    }
}

int largestArea(int *a, int len) {
    
    std::vector< int > area(len, 0);
    
    int n, i, t;
    std::stack<int> St;  
    bool done;

    for (i=0; i<len; i++)
    {
    while (!St.empty())
    {
       if(a[St.top()] >= a[i])
       {
           St.pop();
       }
       else
           break;
    }
    if(St.empty())
       t = -1;
    else
       t = St.top();
    //Calculating Li
    area[i] = i - t - 1;
    St.push(i);
    }

    //clearing stack for finding Ri
    while (!St.empty())
    St.pop();

    for (i=len-1; i>=0; i--)
    {
    while (!St.empty())
    {
       if(a[St.top()] >= a[i])
       {
           St.pop();
       }
       else
           break;
    }
    if(St.empty())
       t = len;
    else
       t = St.top();
    //calculating Ri, after this step area[i] = Li + Ri
    area[i] += t - i -1;

    St.push(i);
    }

    int max = 0;
    //Calculating Area[i] and find max Area
    for (i=0; i<len; i++)
    {
    area[i] = a[i] * (area[i] + 1);
        printf("%d: area: %d\n", i, area[i]);
    if (area[i] > max)
       max = area[i];
    }

    return max;
}

int main() {
    int h[] = {1,2,3,4,2,2,3};
    int n = sizeof(h) / sizeof(int);

    largestArea(h, n);
//     max_area_hist(h, n);
    
}


