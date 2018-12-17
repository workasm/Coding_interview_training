
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

// coins - a list of coins with different denominations,
// some maybe repeated: [1,1,1,2,25,25,30,30,30,..]
// S - the desired sum
void compute_change(int *coins, int n, int S) {

    // a vector of booleans s.t. Q[s] == true if it is feasible to make a change 's'
    std::vector< int > Q(S + 1, 0);
    Q[0] = 1;

    int i, s;
    for(i = 0; i < n; i++) {
        // in descending loop: Q[s - d] is not yet computed
        // for the coin 'i' when Q[s] is being computed
        for(s = S; s >= 1; s--) {
            if(coins[i] <= s)
                Q[s] |= Q[s - coins[i]];
        }
    }

    for(s = 0; s <= S; s++) {
        printf("Q[%d] = %d\n", s, Q[s]);
    }
    printf("\n");
}

float get_avg_sum(std::vector< int >& coins, int S) {
    std::vector< int > Q(S + 1, 100000); // min no of coins to get this sum
    Q[0] = 0;
    int i, s;
    for(i = 0; i < coins.size(); i++) 
    for(s = 1; s <= S; s++) {
        if(s >= coins[i])
            Q[s] = std::min(Q[s], Q[s - coins[i]] + 1);
    }
    int avg = 0;
    for(s = 0; s <= S; s++) {
        avg += Q[s];
    }
    return ((float)avg/S);
}

std::vector< int > coins_set;
float min_avg = 1e10;
std::vector< int > opt_set;

void brute_force(int n_used, int coin_sum, int N, int S) {
//     float best[N]; // best avg to get the sum [1..S] using N coins
//     std::vector< int > coins[S]; // optimal coins set to get [1..S] with minimum avg
//     std::vector< int > parts[S]; // # of coins used to obtain the sum 'S'
// using only 1 coin (which is 1 by default)
//     best[0] = (float)(S + 1) / 2.0;  // avg = {1 + 2 + .. + S-1 + S} / S

    float avg = get_avg_sum(coins_set, S);
    if(min_avg > avg) {
        min_avg = avg;
        opt_set = coins_set;
    }

    if(n_used < N) {
        int next = coins_set[n_used - 1] + 1;
        for(; next <= S - coin_sum; next++) {
            coins_set.push_back(next);
            brute_force(n_used+1, coin_sum + next, N, S);
            coins_set.pop_back();
        }
    }
}

int main() {
//     int x[] = {1, 5, 18, 25};// {1, 2, 5, 5, 10, 10};
//     int n = sizeof(x) / sizeof(int);
    coins_set.push_back(1); // first coin is always 1
    int N = 4;
    brute_force(1, 1, N, 200);

    printf("avg: %.3f; coins: [", min_avg);
    for(int j = 0; j < opt_set.size(); j++) {
        printf(" %d", opt_set[j]);
    }
    printf("]\n");

    return 1;
}

//     brute_force(

//     for(s = 1; s <= S; s++) {
//
//         coins[s - 1] -- previous optimal coin sets
//     }
//
//     int coin_sums = 1;
//     coins.push_back(1);
//     for(int i = 1; i < N; i++) { // using up to (i+1) coins
//
//         int next = coins.back() + 1; // coins appear in sorted order => start from
//                                     // the highest denomination seen so far
//         int best_coin = -1;
//         float min_avg = 1e10;
//         for(; next <= S - coin_sums; next++) {
//             coins.push_back(next);
//             float avg = get_avg_sum(coins, S);
//             coins.pop_back();
//
//             if(min_avg > avg) {
//                 min_avg = avg;
//                 best_coin = next;
//             }
//         }
//         if(best_coin != -1)
//         coins.push_back(best_coin);
//
//         printf("avg: %.3f; coins: [", min_avg);
//         for(int j = 0; j < coins.size(); j++) {
//             printf(" %d", coins[j]);
//         }
//         printf("]\n");
// //         for(s = 1; s < S; s++) { // sums
// //             best[s][i]
// //                 = best[s][i - 1]
// //
// //             int denom = coins[
// //             // coins are sorted hence you can add
// //             // one more coin of denomination coins[s][i-1].last() + 1
// //
// //             coins[s][i - 1] - coin set used for sum 's'
// //         }
//     }
//     

