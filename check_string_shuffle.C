
#include <stdio.h>
#include <string.h>
#include <vector>

/** We are given 3 strings: str1, str2, and str3. Str3 is said to be a shuffle of str1 and str2 if it can be formed by interleaving the characters of str1 and str2 in a way that maintains the left to right ordering of the characters from each string. For example, given str1=abc and str2=def, str3=dabecf is a valid shuffle since it preserves the character ordering of the two strings. So, given these 3 strings write a function that detects whether str3 is a valid shuffle of str1 and str2. */

std::vector< int > cache;

char cch[256];

// provided we know that len(c1) + len(c2) == len(c3)
bool is_shuffle(const char *c1, const char *c2, const char *c3, int i1,
            int i2, int i3) {

    int cidx = i1 * strlen(c2) + i2;
    if(cache[cidx])
        return false;

    cache[cidx] = 1;

    strcpy(cch, c1 + i1);
    printf("checking (%s ", cch);
    strcpy(cch, c2 + i2);
    printf("%s) -- ", cch);
    strcpy(cch, c3 + i3);
    printf("%s\n", cch);
//     printf("checking (%d %d) -- %d\n", i1, i2, i3);

    while(1) {
        char ch1 = c1[i1], ch2 = c2[i2],
                ch3 = c3[i3];
        if(ch3 == '\0')
            return true;

        i3++;
        if(ch1 == ch2 && ch2 == ch3) { // have to explore both alternatives
            if(is_shuffle(c1, c2, c3, i1+1, i2, i3))
                return true;
            return is_shuffle(c1, c2, c3, i1, i2+1, i3);
        } else if(ch1 == ch3)
            i1++;
        else if(ch2 == ch3)
            i2++;
        else {
//             printf("mismatch: %c %c %c\n", ch1, ch2, ch3);
            return false; // not a shuffle
        }
    }
    return false;
}

int main() {

    // this is a worst case: we need to use DP approach here
    char *c1 = "aaaaa", *c2 = "aaaab", *c3 = "aaaabaaaaa";
    int l1 = strlen(c1), l2 = strlen(c2);

    printf("%d %d\n", l1, l2);
    cache.resize((l1+1)*(l2+1), 0);

    printf("is_shuffle: %d\n", is_shuffle(c1, c2, c3, 0, 0, 0));
    return 1;
}




