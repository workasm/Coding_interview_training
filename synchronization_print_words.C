
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>

// m semaphores (one for each thread)
semaphore sem[m];
// semaphores for all but 0th thread are initially blocked
sem[0].init(1);  
sem[1..m-1].init(0);
int word_count = 0;    // shared variable to keep the no of printed words so far

// parallel code
TID = thread_id(); // TID = 0..m-1
while(1) {
    sem[TID].wait(); // wait on semaphore
    if(word_count < n) {   // this code is guaranteed to execute by one thread
        print(word[word_count]); // hence no need for critical section
        word_count++;
    }
    sem[(TID+1)%m].signal(); // signal the next thread in a chain
    if(word_count == n)    // exit gracefully when all words are printed
        break;
}

