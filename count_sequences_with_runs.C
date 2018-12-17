
#include <stdio.h>
#include <memory.h>
#include <string.h>

#include <vector>

//! Given four numbers N, M, K, L. Count the number of possible sequences of N numbers that has exactly M runs, each of the number in the sequence is less than or equal to K and difference between the adjacent numbers is less than equal to L.

#define ABS(x) ((x) < 0 ? -(x) : (x))

int total_count = 0;
int N = 4, M = 2, K = 9, L = 1;
std::vector< int > seq;

// n_placed: number of digits in a sequence being placed
// n_last: last digit placed (for comparison)
// n_runs: # of runs counted so far
// dir: current direction: decreasing(0), increasing(1) or undefined(-1)
void count_sequences(int n_placed, int n_last, int n_runs, int dir) {
    seq.push_back(n_last);
    if(n_placed == N) {
        if(n_runs == M) {
            total_count++;
            printf("%d: ", total_count);
            for(typeof(seq.begin()) i = seq.begin(); i != seq.end(); i++) {
                printf("%d ", *i);
            }
            printf("\n");
        }
        seq.pop_back();
        return;
    }
    
    for(int i = 1; i <= K; i++) {
        int diff = i - n_last;
        // difference between adjacent elements is too large
        if(ABS(diff) > L)
            continue;
        
        if(diff == 0) { // duplicate element: break the current sequence
            // already have enough runs: no need to explore this path further
            if(n_runs == M) 
                continue;
            count_sequences(n_placed+1, i, n_runs+1, -1);
        } else if(diff < 0) {
            if(dir == -1) { // start a new decreasing sequence
                count_sequences(n_placed+1, i, n_runs, 0);
            // current sequence is decreasing: continue this sequence
            } else if(dir == 0) {
                count_sequences(n_placed+1, i, n_runs, 0);
            // current sequence is increasing: break it
            } else { // dir == 1
                if(n_runs == M) // have enough runs already
                    continue;
                count_sequences(n_placed+1, i, n_runs+1, 0);
            }
        } else { // diff > 0

            if(dir == -1) { // start a new increasing sequence
                count_sequences(n_placed+1, i, n_runs, 1);
            // current sequence is increasing: continue this sequence
            } else if(dir == 1) {
                count_sequences(n_placed+1, i, n_runs, 1);
            // current sequence is decreasing: break it
            } else { // dir == 0
                if(n_runs == M) // have enough runs already
                    continue;
                count_sequences(n_placed+1, i, n_runs+1, 1);
            }
        }
    }
    seq.pop_back(); // pop the current element
}

int main() {
    for(int i = 1; i <= K; i++) {
        count_sequences(1, i, 1, -1);
    }
    return 1;
}


