    
#include <iostream>
#include <vector>
#include <stdio.h>

void transform_array(char *s[], int len) {
    
    int row_sz = len / 3; // size of a single row
    int new_row_sz = 3; // size of a new row
    
    int idx = 1, start_i = idx;
    int lowest = idx + 1; // lowest unreplaced index

    int l = len;
    while(l--) {

        int row = idx / row_sz, // get a row index
            col = idx % row_sz; // column index
        int next_i = col * 3 + row; //  transposed index

        if(next_i == start_i) { // found a loop
            printf("loop found at: %d\n", next_i);
            start_i++;
            idx = start_i;

            continue;
        }
        printf("%d (%s) <-> %d (%s)\n", start_i, s[start_i], next_i,
            s[next_i]);

        std::swap(s[start_i], s[next_i]);
        idx = next_i;
    }

    for(idx = 0; idx < len; idx++) {
        printf("%s ", s[idx]);
    }
    printf("\n");
}

int get_index(int idx, int N) {
    return (idx % 3) * N + (idx / 3);
}

void transform_array2(char *s[], int len) {
    int N = len / 3;
    for(int i = 0; i < len; i++) {
        int new_idx = get_index(i, N);
        while(new_idx < i) {
            new_idx = get_index(new_idx, N);
        }
        printf("i: %d; new_idx: %d\n", i, new_idx);
        std::swap(s[i], s[new_idx]);
    }

    for(int i = 0; i < len; i++) {
        printf("%s ", s[i]);
    }
    printf("\n");
}

int main() {

//     char *s[] = {"a1","a2","a3","a4", "b1","b2","b3","b4", "c1","c2","c3","c4"};

//     char *s[] = {"a1","a2","a3","a4","a5", "b1","b2","b3","b4","b5", "c1","c2","c3","c4","c5"};

char *s[] = {"a1","a2","a3", "b1","b2","b3", "c1","c2","c3"};

//     transform_array(s, 12);

    transform_array2(s, 9);
    
    return 1;

}