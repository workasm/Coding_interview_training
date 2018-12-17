
#include <stdio.h>

void print_array(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n\n");
}

// A size is 2n
void permute_numbers(int *A, int n) {
    
    int mod = 2*n-1, count = 1;
    int i = 1, start = A[i];
    
    while(count < mod) {
        int next = (2*i) % mod, tmp = A[next];
        A[next] = start;
        i = next;
        start = tmp;

        if(i <= count) {
            i = count+1;
            start = A[i];
        }            

        printf("next index = %d\n", next);
        print_array(A, 2*n);
        count++;
    }    
}

int main() {

    int A[] = {0, 2, 4, 6, 8, 10, 12,
            1, 3, 5, 7, 9, 11, 13};
    int n = 7;//sizeof(A) / (sizeof(int) * 2);
    permute_numbers(A, n);

    print_array(A, 2*n);
    return 1;
}




