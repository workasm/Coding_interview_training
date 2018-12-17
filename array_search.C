
#include <stdio.h>


// #define abs(x) ((x) 

void search_num(int a[], int n, int p) {

    //number to be searched is p
    bool found = 0;
    for(int i = 0; i < n; ) {
        printf("i: %d\n", i);
        if(a[i] == p) {
            found = 1;
            break;
        }
        
        i += (p > a[i] ? p - a[i] : a[i] - p);
    }
    printf("found: %d\n", found);
}


int main() {

//     int a[] = {1,0,-1,-2,-3,-4,-3,-2,-1,0,1,2,3,4};
    int a[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,0};

//5,4,5,6,7,6,7,8,3,2,3,4,5,6,7,8,9,10,9};
//                 3,4,5,6,7,8,9,10};
    int n = sizeof(a) / sizeof(int);

//     search_num(a, n, 0);


     char arr[] = "12345abcde";
     int len = 10;

     int k=0;
     for(int i = len/2; i < len - 1; i++) {
            for(int j = i - 1; j >= (2*k+1); j--){
                char c = arr[j];
                arr[j] = arr[j+1], arr[j+1] = c;
//                 std::swap(a[j],a[j+1]);
                printf("%s\n", arr);
            }
            k++;
            printf("==================== %s\n", arr);
        }

    return 1;
}




