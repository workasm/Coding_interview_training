
Given an array of random numbers. Find the longest consecutive sequence.
For ex
Array 100 3 200 1 2 4
Ans 1 2 3 4
Array 101 2 3 104 5 103 9 102
Ans 101 102 103 104

Can we do it in one go on array using extra space??

1. go through array and add elements to hash
2. for each added element 'i' check if 'i-1' and 'i+1' are
already in the hash
3. if any of them already there merge the sets containing elements 'i-1'
'i' and 'i+1' using union-set data structure. Update the parent pointer
of this structure which contains the number of elements in the set.
4. keep the pointer on the max_so_far set data structure

NOTE: union-set is implemented using path-compression during element find.
