
#include <stdio.h>
#include <memory.h>
#include <string.h>

#include <set>

#define rows 5
#define cols 5

// char A[][cols] =
//     {{'A','C','P','R','C'},
//     {'X','S','O','P','C'},
//     {'V','O','V','N','I'},
//     {'W','G','F','M','N'},
//     {'Q','A','T','I','T'}};

char A[][cols] =
    {{'A','C','P','T','C'},
    {'X','I','I','I','F'},
    {'V','C','M','I','O'},
    {'W','R','C','S','T'},
    {'Q','O','S','R','O'}};


bool visited[rows][cols];    

bool find_pattern(const char *pattern, int i, int j, int idx) {

    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;

    if(visited[i][j])
        return false;

    if(A[i][j] != pattern[idx])
        return false;

    printf("(%d; %d): %c\n", i, j, A[i][j]);
    
    visited[i][j] = true;

    idx++;
    if(idx == strlen(pattern)) {
        printf("pattern found !\n");
        return true;
    }
    
    if(find_pattern(pattern, i-1, j, idx))
        return true;
    if(find_pattern(pattern, i, j-1, idx))
        return true;
    if(find_pattern(pattern, i-1, j-1, idx))
        return true;
    if(find_pattern(pattern, i-1, j+1, idx))
        return true;
    if(find_pattern(pattern, i, j+1, idx))
        return true;
    if(find_pattern(pattern, i+1, j, idx))
        return true;
    if(find_pattern(pattern, i+1, j-1, idx))
        return true;
    if(find_pattern(pattern, i+1, j+1, idx))
        return true;

    return false;
}


int main() {

    const char *pattern = "MICROSOFT";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {

            if(A[i][j] == pattern[0]) { // find the first match
                memset(visited, 0, rows*cols);
                find_pattern(pattern, i, j, 0);
            }
        }
    }
    
    return 1;
}


