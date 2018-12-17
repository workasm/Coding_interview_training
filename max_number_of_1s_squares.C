
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <map>

// #include <math.h>
#include <stdio.h>

/** 25-26,83-84,85-86,89-90,93-94,95-96,103-104,107-108,109-110,113-114,117-118,119-120,123-124,133-134,149-150,151-152,153-154,155-156,157-158,159-160
*/

void add_char(char c) {
    // pointers to keep track of odd and even-length palindromes
    static int odd = 0, even = -1;
    static int idx = 0;     // current position in the stream
    static char stream[256];

    stream[idx] = c;
    stream[idx+1] = '\0';

    if(odd >= 0 && stream[odd] == c) {
        odd--;
        if(odd < 0) {
            printf("odd palindrome: %s\n", stream);
            odd = idx - 1;
        }
    } else
        odd = idx - 1;

    if(even >= 0 && stream[even] == c) {
        even--;
        if(even < 0) {
            printf("even palindrome: %s\n", stream);
            even = idx;
        }
    } else
        even = idx;

    printf("%c: odd: %d; even: %d\n", c, odd, even);
    idx++;
}

#define R 6
#define C 5
//#define R 6
//#define C 5
// #define R 8
// #define C 10

int S[R][C];
int M[R][C] =  {
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}};
// {0,1,1,0,0,0,0,1,1,1},
// {0,0,0,0,0,1,0,1,1,1},
// {1,1,0,1,1,1,1,1,1,0},
// {0,0,1,0,0,1,0,1,1,1},
// {1,1,0,0,0,1,0,0,1,1},
// {1,1,1,0,0,1,1,0,1,0},
// {1,1,1,0,1,0,0,1,0,0},
// {0,1,1,1,1,1,1,0,0,0}};
//     {1,1,0,0,1},
//     {1,1,1,1,0},
//     {1,1,0,1,1},
//     {1,1,0,0,1}};

void fillin(int r1, int c1) { // mark overlapping squares
    int sz = S[r1][c1], i, j;
    int r0 = r1 - sz + 1, c0 = c1 - sz + 1;
    for(i = r0; i <= r1; i++)
    for(j = c0; j <= c1; j++) {
        int s = S[i][j];
        if(i - s + 1 >= r0 && j - s + 1 >= c0)
           S[i][j] = 0;
    }
}

void printMaxSubSquare()
{
  int i,j;
  int max_of_s, max_i, max_j;
  /* Set first column of S[][]*/
  for(i = 0; i < R; i++)
     S[i][0] = M[i][0];
  /* Set first row of S[][]*/
  for(j = 0; j < C; j++)
     S[0][j] = M[0][j];
  /* Construct other entries of S[][]*/
  for(i = 1; i < R; i++)
  {
    for(j = 1; j < C; j++)
    {
      if(M[i][j] == 1)
        S[i][j] = std::min(std::min(S[i][j-1], S[i-1][j]), S[i-1][j-1]) + 1;
      else
        S[i][j] = 0;
    }
  }
    printf("Input:\n");
      for(i = 0; i < R; i++) {
    for(j = 0; j < C; j++) {
        printf("%d ", M[i][j]);
    }
    printf("\n\n");
    }
    int cnt = 0;
    for(i = R-1; i >= 0; i--)
    for(j = C-1; j >= 0; j--) {
        if(S[i][j] <= 0)
            continue;
        printf("%d: size: %d; bottom-right: (%d; %d)\n", ++cnt, S[i][j], i, j);
        fillin(i, j);
    }
    printf("\n");
}

int main()
{
  printMaxSubSquare();
}

// int main() {
//     const char *s = "caaaac";
//     
//     for(int i = 0; s[i] != 0; i++)
//         add_char(s[i]);
//     
//     return 0;
// }



