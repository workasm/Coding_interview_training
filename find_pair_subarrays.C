
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

static void getMaxLength(int *arr, int len) {
        
        int maxCount = 0;
        int s1=-1, s2=-1;
        for(int i=0;i<len;i++) {
            int head = i; int tail = len-1;
            int max = 0; // Max value of smaller sub-array
            int min = 10000000; // Min value of larger sub-array
            int currentCount = 0; // Max length sub-array for elements starting at index i
            int startMax = -1; // 0 = head represents larger sub-array ; 1 = tail represents larger sub-array

            while(tail > head) {
                if(startMax == -1)
                {
                    startMax = arr[head] > arr[tail] ? 1 : 0;
                    max = (startMax == 1) ? MAX(max, arr[tail]) : MAX(max, arr[head]);
                    min = (startMax == 1) ? MIN(min, arr[head]) : MIN(min, arr[tail]);
                    head++;
                    tail--;
                    currentCount++;
                    
                    if(currentCount >= maxCount) {
                        int start = head - currentCount,ii;
                        printf("found: %d [", currentCount);
                        for(ii = start; ii <= start+currentCount; ii++) 
                            printf("%d ", arr[ii]);
                        printf("] and [");
                        
                        start = tail;
                        for(ii = start; ii <= start+currentCount; ii++) 
                            printf("%d ", arr[ii]);
                        printf("]\n");
                        
                    }
                    maxCount = (currentCount >= maxCount) ? currentCount : maxCount;
                    continue;
                }
                else {
                    if((startMax == 1) && 
                            ((arr[head] < arr[tail]) || (arr[head] < max) || (arr[tail] > min))) {
                        startMax = -1; 
                        max = 0; 
                        min = 10000000; 
                        //head = i; 
                        currentCount = 0;
                        continue;
                    }
                    else if((startMax == 0) && ((arr[head] > arr[tail]) || (arr[head] > min) || (arr[tail] < max))) {
                        startMax = -1; 
                        max = 0; 
                        min = 10000000; 
                        //head = i; 
                        currentCount = 0; 
                        continue;
                    }
                }

                max = (startMax == 1) ? MAX(max, arr[tail]) : MAX(max, arr[head]);
                min = (startMax == 1) ? MIN(min, arr[head]) : MIN(min, arr[tail]);
                head++; 
                tail--; 
                currentCount++;
                maxCount = (currentCount >= maxCount) ? currentCount : maxCount;
                
                    if(currentCount >= maxCount) {
                        int start = head - currentCount,ii;
                        printf("found: %d [", currentCount);
                        for(ii = start; ii <= start+currentCount; ii++) 
                            printf("%d ", arr[ii]);
                        printf("] and [");
                        
                        start = tail;
                        for(ii = start; ii <= start+currentCount; ii++) 
                            printf("%d ", arr[ii]);
                        printf("]\n");
                        
                    }
            }
        }
        printf("Max Length = %d\n", maxCount);
    }

    
void find_pair_subarrays(int *a, int n) {
 
    int i, j, k, w, cnt = 0;
    
    // this is subarray lengths
    for(i = n/2; i >= 1; i--) {
        printf("length: %d\n", i);
        // this is a starting index of the first subarray
        for(j = 0; j <= n - i*2; j++) {
            for(k = j + i; k <= n-i; k++) {
                
                cnt++;
                printf("s1 = [");
                for(w = j; w < j + i; w++) {
                    printf("%d ", a[w]);
                }
                printf("]; s2 = [");
                for(w = k; w < k + i; w++) {
                    printf("%d ", a[w]);
                }
                printf("]\n");
            }
        }
        
    }
    printf("cnt = %d\n", cnt);
}


int main() {

    int a[] = {6,5,4,1,3,7};
    int n = sizeof(a) / sizeof(int);

//     find_pair_subarrays(a, n);
    
    getMaxLength(a, n);
    
//     longestSubArray(a, n);
    return 1;
}


