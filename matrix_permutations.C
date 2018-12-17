

#include    <stdio.h>
#include    <stdlib.h>
#include    <memory.h>
#define     MAX 20

char        num[MAX + 1];
int         n; 

void createCyclicMatrix ()
{
    char    *p[MAX], temp[2*MAX];
    int     i, j;
    /* create the cyclic permutation matrix P as an array of pointers */ 
    memcpy (temp, num + 1, n);
    memcpy (temp + n , num + 1, n);
   
    for (i = 0; i < n; ++i)
        p[i] = temp + n - i;
   
    /* generate the 2n permutations from the cyclic permutation matrix P */
    for (i = 0; i < n; ++i)
        {
        /* print the ith row */
        for (j = 0; j < n; ++j)
            printf ("%d ", *(p[i] + j));
        printf ("\n");
        /* print the ith column */
        for (j = 0; j < n; ++j)
            printf ("%d ", *(p[j] + i));
        printf ("\n");
        }
}

void rightRotate (int f, int l)
{
    char    temp [2*MAX], *saveptr;
    int     i;
    saveptr = num + f;
    memcpy (temp , saveptr, l);
    memcpy (temp + l, saveptr, l);
    memcpy (saveptr, temp + l - 1, l);
}


void matrixPermute (int k)
{
    int     i, temp;
    if  (k == 3) 
        {
        createCyclicMatrix ();
        return;
        }
    temp = k - 1;
    for (i = 0; i < temp ; ++i) 
        {
        rightRotate (1, temp);
        matrixPermute (temp);
        } 
}

main (int argc, char *argv[])
{
    int     i;
    if  (argc != 2)
        {
        fprintf (stderr, "Usage: permute <string>\n");
        exit (1);
        }
    n = atoi (argv [1]);
    if  (n < 3 || n > MAX)
        {
        fprintf (stderr, "number must be between 3 and %d\n", MAX);
        exit (1);
        }
    for (i = 1; i <= n; ++i)
        num [i] = i;
    matrixPermute (n);
}
