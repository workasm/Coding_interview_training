
#include <stdio.h>
#include <string.h>
#include <memory.h>

// find a longest subarray which consists of consecutive ints
// of a given array
void longest_subarray(int *a, int n) {

    int p1 = 0, p2 = 0; // bounds for subarray found so far
    int i, j;
    for(i = 0; i < n - 1; i++) {
        int ch = a[i], sum = ch, xsum = ch;
        // indices of min-max chars in the range [i; j]
        int minc = ch, maxc = ch;
        for(j = i + 1; j < n; j++) {

            int ch = a[j];
            xsum ^= ch,  sum += ch; // compute two sums '+' and 'xor'
            if(ch < minc)
                minc = ch;
            else if(ch > maxc)
                maxc = ch;
            // if no of elements is not equal => no need to make tests
            if(maxc - minc != j - i)
                continue;

            int sum_check = maxc*(maxc+1) / 2 - minc*(minc-1)/2;
            if(sum_check == sum && j - i > p2 - p1) {
                int xcheck = 0;
                for(int m = minc; m <= maxc; m++)
                    xcheck ^= m;
                printf("j: %d; sum %d %d; xsum: %d %d\n", j,
                        sum, sum_check, xsum, xcheck);
                if(xsum == xcheck) {
                    p1 = i, p2 = j; // found a match
                    printf("found match: %d %d\n", p1, p2);
                }
            }
        }
    }

    for(i = p1; i <= p2; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
//     int a[] = {11,1,23,6,7,3,3,6,3,3,4,2,235,2,234,234};
    int a[] = //{1,3,3,3,5,6};
            {1,1,4,4,5,5,8,8};
        //{5,5,1,6,7,3,2,4,3,1,9};
    int n = sizeof(a) / sizeof(int);
    longest_subarray(a, n);
    return 1;
}

