
#include <stdio.h>

typedef unsigned long ulong;

ulong N;    // number of bits in words
ulong K;    // number of bits in words
ulong *x;  // elements in combination at x[1] ... x[k]

ulong ct;   // count objects

void visit()
{
    for(int j = 1; j <= K; j++)
        printf("%d ", x[j]);
    printf("\n");
}
// -------------------------


void comb_gray(ulong n, ulong k, bool z)
{
    if ( k==n )
    {
        for (ulong j=1; j<=k; ++j)  x[j] = j;
        ++ct;
        visit();
        return;
    }

    if ( z )  // forward:
    {
        comb_gray(n-1, k, z);
        if ( k>0 )  { x[k] = n;  comb_gray(n-1, k-1, !z); }
    }
    else     // backward:
    {
        if ( k>0 )  { x[k] = n;  comb_gray(n-1, k-1, !z); }
        comb_gray(n-1, k, z);
    }
}
// -------------------------


void comb_gray_compl(ulong n, ulong k, bool z)
{
    if ( k==n )
    {
        for (ulong j=1; j<=k; ++j)  x[j] = j;
        ++ct;
        visit();
        return;
    }

    if ( z )  // forward:
    {
        if ( k>0 )  { x[k] = n;  comb_gray_compl(n-1, k-1, z); }
        comb_gray_compl(n-1, k, !z);
    }
    else     // backward:
    {
        comb_gray_compl(n-1, k, !z);
        if ( k>0 )  { x[k] = n;  comb_gray_compl(n-1, k-1, z); }
    }
}
// -------------------------

int
main(int argc, char **argv)
{
    N = 7;
    K = 3;
    x = new ulong[N+1];

    bool cq = 0;
    bool rq = 0;
    
    rq = !rq;

    if ( K>N )  { return 1; }

    ct = 0;
    if ( 0==cq )  comb_gray(N, K, rq);
    else          comb_gray_compl(N, K, rq);

    //cout << "ct=" << ct << endl;

    delete [] x;

    return 0;
}
