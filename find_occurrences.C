
#include <stdio.h>

bool find(char *pa, char *pb) {

    if(pb == 0)
        return true;
    if(pa == 0)
        return false;

    unsigned aux[256];
    for(char *s = pb; *s != 0; s++)
        aux[*s]++;    
    
    for(char *s = pa; *s != 0; s++) 
        if(aux[*s] != 0)
            aux[*s]--;
    
    for(int i = 0; i < 256; i++)
        if(aux[i] != 0)
            return false;
    return true;
}

void parse_array(int *ary, int length) {
int i = 0;
int j = 1;
while((i <= length) && (j <= length))
{
    for (; i < length; i += 2)
        if(ary[i] != 0)
            break;

    if(i == length)
        break;
    for (; j < length; j += 2)
        if(ary[j] != 1)
            break;

    if(j == length)
        break;
    ary[i] = 0;
    ary[j] = 1;
    i += 2;
    j += 2;
}

printf("i = %d j = %d length = %d\n", i, j, length);
}


int main() {
    int ary[] = {0, 1, 0, 1, 0, 1, 0, 1, 0};
    int sz = sizeof(ary) / sizeof(int);
    parse_array(ary, sz);
    
    for(int i = 0; i < sz; i++) 
        printf("%d ", ary[i]);
    printf("\n\n");

}

