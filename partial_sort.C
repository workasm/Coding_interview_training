
Partial sorting: Given an array A of n elements and a value
1 <= m <= n, rearrange A so that its first m positions contain
the m smallest elements in ascending order
For m = Theta(n) it might be OK to sort the array; otherwise, we
are doing too much work

Idea #1: Partial heapsort
Build a heap with the n elements and perform m extractions of
the heap's minimum
The worst-case cost is O(n + mlog n)
This the traditonal implementation of C++ STL's partial sort

Idea #2: On-line selection
Build a heap with the m first elements; then scan the
remaining n - m elements and update the heap as needed;
finally extract the m elements from the heap
The worst-case cost is O(n logm)
Not very attractive unless m is very small or if used in on-line
settings

Idea #3: Quickselsort
Find the mth smallest element with quickselect, then quicksort
the preceding m - 1 elements
The average cost is O(n + mlogm)
Uses two basic algorithms widely available (and highly tuned
for performance in standard libraries)

while(more lines to read) {

    line = readline();
    linenum = linenum + 1;
    r = random(0, linenum);
    if(r == 0)
        return line;
}