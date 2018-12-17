
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define swap(x, y) { int temp = (x); (x) = (y); (y) = temp; }

void print_array(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void compute_sum(int *a, int n) {

    int p1 = 0, p2 = 0;
    int cur_sum = 0, max_sum = a[0];

    for(int i = 0, j = 0; i < n; i++) {
        
        cur_sum += a[i];
        if(cur_sum > max_sum) {
            max_sum = cur_sum;
            p1 = j;
            p2 = i;
        }
        if(cur_sum < 0) {
            j = i + 1;
            cur_sum = 0;
        }        
        printf("[%d; %d]: cur_sum: %d; max_sum: %d\n",
            j, i, cur_sum, max_sum);
    }
    printf("sum = %d [%d; %d]\n", max_sum, p1, p2);    
}

void sum_on_circle(int *a, int n) {

    int p1 = 0, p2 = 0;
    int cur_sum = 0, max_sum = a[0];

    printf("sz = %d\n", n);

    for(int i = 0, j = 0; i < 2*n - 1; i++) {
        // ensure that we do not make more than turn around the circle
        if(i - j >= n) {
            do { // subsequence cannot start from negative number
                cur_sum -= a[j % n];
                j++;
            } while(a[j % n] < 0 && j <= i);

            if(cur_sum > max_sum) {
                max_sum = cur_sum;
                p1 = j;
                p2 = i - 1;
            }
        }
        cur_sum += a[i % n];
        if(cur_sum < 0) {
            j = i + 1;
            cur_sum = 0;
        }        

        if(cur_sum > max_sum) {
            max_sum = cur_sum;
            p1 = j;
            p2 = i;
        }
        printf("[%d; %d]: cur_sum: %d; max_sum: %d\n",
            j, i, cur_sum, max_sum);
    }
    printf("sum = %d [%d; %d]\n", max_sum, p1, p2);
}

void sum_on_circle2(int *a, int n) {

int max_start=0, max_end =0, maxv = 0, sum  = 0;

for(int i = 0; i < n; i++) {
    sum+= a[i];
    if(sum<0)
      { sum=0; max_start =i;}
    if(maxv<sum) {
       maxv=sum; max_end = i;
    }
}
printf("1 max_start: %d; max_end: %d; sum: %d\n", max_start, max_end, maxv);

for(int i = 0; i < max_start; i++) {
    sum+= a[i];
    if(sum<0)
       break;
    if(maxv<sum) {
       maxv=sum;max_end = i;
    }
}

printf("2 max_start: %d; max_end: %d; sum: %d\n", max_start, max_end, maxv);

}

int main() {

    int a[] = //{8,-8,9,-9,10,-11,12};
//         {2, 2, -10, 16, -8, 9, -2, 4};
//             {2, 5, -6, 3, 7};
{-3, 5, 6, -2, -2, 2, 2};
/*  0  1  2   3   4  5  6
  7  8  9  10  11 12*/
//              {1, -2, -7, -1, -8, 3};
    int n = sizeof(a) / sizeof(int);    

    sum_on_circle(a, n);
    sum_on_circle2(a, n);
    return 1;
}

