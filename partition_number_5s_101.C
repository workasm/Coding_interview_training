    
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <string.h>

/*! partition minimal number of power's of 5 */

#define MAX_NUMS 6
char g_bufs[MAX_NUMS][128];
char *g_strs[MAX_NUMS];

char *ul2binstr(unsigned num, char *s, size_t len)
{
    s[--len] = '\0';
    do {
        s[--len] = ((num & 1) ? '1' : '0');
    } while ((num >>= 1) != 0);
    return s + len;
}

char bbb[256];
int *g_lens, g_len = 0;

// return min number of parts of -1 if not possible
int search_rec(const char *s, int l, int r) {
 
   int *plen = g_lens + l * g_len + r;
   if(plen[0] != 0)
       return plen[0];
    
   for(int i = 0; i < MAX_NUMS; i++) {
       if(r - l + 1 == strlen(g_strs[i]) &&
           strncmp(s + l, g_strs[i], r - l + 1) == 0) {
            strcpy(bbb, s);
            bbb[r+1] = '\0';
           printf("checking: %s FOND: %s\n", bbb + l, g_strs[i]);
            plen[0] = 1;
            return 1;
       }
   }
   if(l == r) {// we have a single '0' left => no way to split it
        plen[0] = -1;
        return -1;
   }
   
   int nsplits = -1;
   for(int split = l + 1; split <= r; split++) {
        //[l; split-1] and [split; r]
        int res1 = search_rec(s, l, split-1);
        if(res1 == -1)
            continue;
        int res2 = search_rec(s, split, r);
        if(res2 != -1) {
            if(nsplits == -1 || nsplits > res1+res2)
                nsplits = res1 + res2;
        }
   }
   
   strcpy(bbb, s);
    bbb[r+1] = '\0';
   printf("checking: %s found: %d\n", bbb + l, nsplits);
   plen[0] = nsplits;
   return nsplits;
}

int main()
{
    char bbf[128];
    int x, j;
    for(x = 1, j = 0; j < MAX_NUMS; x *= 5, j++) {
        g_strs[j] = ul2binstr(x, g_bufs[j], 128);
        printf("x: %d; %s\n", x, g_strs[j]);
    }

    const char *ss = "1111101101110000110101";

    g_len = strlen(ss);
    g_lens = new int[g_len*g_len];
    memset(g_lens, 0, g_len*g_len);
    
    int ret = search_rec(ss, 0, g_len-1);
    printf("result: %d\n", ret);
        
    delete []g_lens;
    return 0;
}

