
#include <stdio.h>

#define rows 5
#define cols 5

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }

void print_array(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}


// usually l <= r && t <= b
struct sub_m {
    sub_m() { w = 0, h = 0, s = 0; }
    int w, h; // size of this submatrix
    int s; // stored sum
};

void find_submatrix(int A[rows][cols]) {

    sub_m max_sub; // empty square
    max_sub.s = 0;
    
    sub_m S[rows][cols];

    int i, j, k;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            // compute m[i][j] with bottom-right corner [i,j]
            // we can use m[i-1,j] and m[i,j-1] 
            int s1 = 0, s2 = 0, s3 = 0;
            sub_m& s = S[i][j];

            s.s = A[i][j];

            if(i == 0) { // first row
                s.w[0] = (j == 0 ? 0 : S[i][j-1].w[0]) + 1;
                s.h[0] = 1;
                continue;
            } else if(j == 0) { // first column
                s.w[0] = 1;
                s.h[0] = S[i-1][j].h[0] + 1;
                continue;
            }
            

            if(i != 0) {    // 
                sub_m& x = m[i-1][j];
                s1 = x.s;
                // add row i in range [x.l; x.r] to s1
                for(k = x.l; k <= x.r; k++)
                    s1 += A[i][k];
                printf("s1: horizontal [%d - %d]: %d\n", x.l, x.r, s1);
                if(s1 >= ss.s) {
                    ss.l = x.l; ss.t = x.t;
                    ss.s = s1;
                }
            }
            if(j != 0) {    // 
                sub_m& x = m[i][j-1];
                s2 = x.s;
                // add row j in range [x.t; x.b] to s1
                for(k = x.t; k <= x.b; k++)
                    s2 += A[k][j];
                printf("s2: vertical [%d - %d]: %d\n", x.t, x.b, s2);
                if(s2 >= ss.s) {
                    ss.l = x.l; ss.t = x.t;
                    ss.s = s2;
                }
            }
//             if(i != 0 && j != 0) {    //
//                 sub_m& x = m[i-1][j-1];
//                 s3 = x.s;
//                 // add row i in range [x.l; x.r] to s1
//                 for(k = x.l; k <= x.r; k++)
//                     s3 += A[i][k];
//                 for(k = x.t; k <= x.b; k++)
//                     s3 += A[k][j];
//                 s3 += A[i][j];
// 
//                 printf("s3: diag [%d - %d]: %d\n", x.l, x.r, s3);
//                 if(s3 >= ss.s) {
//                     ss.l = x.l; ss.t = x.t;
//                     ss.s = s3;
//                 }
//             }
            printf("[%d;%d] - %d\n", i,j, m[i][j].s);
            if(ss.s > max_sub.s)
                max_sub = ss;
        }
    }
    
    printf("[%d;%d] - [%d;%d]: %d\n", max_sub.l, max_sub.r,
            max_sub.t, max_sub.b, max_sub.s);
}



// find a submatrix with maximum sum
void max_sum_submatrix(int A[rows][cols], int rows_, int cols_) {

    int vps[rows][cols];
    int i, j, k;

    // calculate vertical prefix sums along each column
    for(j = 0; j < cols; j++) {
        vps[0][j] = A[0][j];
        for(i = 1; i < rows; i++) {
            vps[i][j] = vps[i-1][j] + A[i][j];
        }
    }

    // this is the result, stores [top,left,bottom,right]
    int max_sum = A[0][0], t = 0, l = 0, b = 0, r = 0;
    for(i = 0; i < rows; i++) {
        for(k = i; k < rows; k++) { // run Kadane's algorithm over all
                                    // colums for rows in the range [i..k]
            int loc_sum = 0, loc_start = 0;
            for(j = 0; j < cols; j++) {
                int val = vps[k][j] - (i == 0 ? 0 : vps[i-1][j]);
    
                loc_sum += val;
                if(loc_sum < 0) {
                    loc_sum = 0;
                    loc_start = j + 1;
                } else if(loc_sum > max_sum) {
                    t = i, b = k;
                    l = loc_start, r = j;
                    max_sum = loc_sum;
                }
            }
        }
    }

    printf("max_sum: %d [%d;%d - %d;%d]\n", max_sum, l, r, t, b);

}

int main() {

// int A[rows][cols] = {
//     {1, 2, -1},
//     {-3, 1, 4},
//     {1, -5, -2}};

    int A[rows][cols] = {
        {1,-3,  2,-1, 2},
        {-2,-1, -2,2, -3},

        {-1, 3, 3,11, -1},
        {2, -1, -3,1, 5},
        {0,0, 0,0,0 }};

//     int A[rows][cols] =
//         {{3,-2,2,-2},   
//          {-1, 1,1, -1}, 
//          {-3, 3,-3, 3}, 
//          {-1, 1,-1, 2}};

    max_sum_submatrix(A,0,0);
    find_submatrix(A);    

    return 1;
}

