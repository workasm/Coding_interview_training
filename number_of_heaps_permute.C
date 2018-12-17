3

Given an array 1 to N , how many permutations of it will be Min -Heap of of N! possible permutations

1 will be the root always . We can always calculate the nodes on left and right of roots
given n as it is a heap.
Now T(n) = T(k) * T(n-k-1) * C(n-1,k) where k = number of nodes on left

I think it is you not understanding the notation.
Take T(10). Here the left subtree has 6 nodes, the right subtree 3 nodes. The root is the global minimum element. The left subtree can be chosen in 9C6 ways. The elements can be distributed in T(6) ways. The 3 elements in the right substree can be distributed in T(3) ways.
That gives the formula
T(10) = 9C6 * T(6) * T(3).