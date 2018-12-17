


/**

compositions of n into exact k parts is the same
as compositions of (n-k) into at most k parts because we simply subtract 1
from each one:

n = 5 k = 3

1 2 2
2 1 2
2 2 1
3 1 1
1 3 1
1 1 3

corresponing compositions:
n = 2 k = 3 (at most 3 parts)
     combination of '2' objects out ouf '4'
0 1 1    0 x 0 x   
1 0 1    x 0 0 x
1 1 0    x 0 x 0
2 0 0    x x 0 0
0 2 0    0 x x 0
0 0 2    0 0 x x

suppose P(n,k) - # of compositions of n into at most k parts
Q(n,k) - # of compositions of n into exactly k parts,
hence we have:

P(n,k) = Q(n + k,k) = C(n + k - 1, n)
combinations of 'n' objects out of 'n + k - 1'

but Q(n,k) = C(n - 1, n - k)

*/