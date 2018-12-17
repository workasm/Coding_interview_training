
#include <stdio.h>
#include <string.h>

// computes longest common substring of two strings
void LCS(char *s, char *t) {

    int m = strlen(s),
        n = strlen(t);

    printf(" %d %d\n", m, n);
    int *L = new int[n * m];
    memset(L, 0, n*m*sizeof(int));

    int len = (m > n ? m : n);
    int z = 0, end_i = -1; // length of the LCS found so far and the index
                        // where the common substring of 's' ends

    // L[i][j] - length of the LCS of s[0..i] and t[0..j]
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            if(s[i] != t[j])
                continue;

            int *pL = L + i*n + j;
            if(i == 0 || j == 0)
                pL[0] = 1;
            else {
                pL[0] = pL[-n - 1] + 1;
            }
            if(pL[0] > z) {
                z = pL[0];
                end_i = i;
            }
            if(pL[0] == z) {
                // meaning that s[0..i] and t[0..j] have a common substring
                // of length 'z', save the terminating index
                end_i = i;
//                 printf("%d: LCS found: %s\n", z, LCS);
            }
        }
    }

    if(end_i != -1) {
//         s[end_i-1] = '\0'; // place terminating char to show this str 
        printf("LCS found: %d %d (%s)\n", z, end_i, s + end_i - z + 1);
    }

    delete []L;
}


int main() {

    char *s1 = "privet! kak dela?";
    char *s2 = "zdorova kak dila 4ert? privet!";

    LCS(s1,s2);
    return 1;
}

