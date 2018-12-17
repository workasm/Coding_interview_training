
#include <stdio.h>
#include <memory.h>
#include <string.h>

#include <vector>

/** Given a set of non overlapping intervals
Example 1 :(1,4) (6,10) (14, 19) and another interval (13, 17) merge them as (1,4) (6,10) (13,19)

Example 2: (1,5) (6, 15) (20, 21) (23, 26) (27, 30) (35, 40)
New interval (14, 33)
Output should be
(1,5) (6, 33) (35, 40)

This is because the new interval overlaps with (6, 15) (20, 21) (23, 26) (27, 30) */

// I hope this is correct logic
// - Represent all the intervals in a sorted array
// - Insert the interval to be merged in this array
// - And now keep iterating this array in ascending order
// - If the given start Interval is in even position(array starts from 0) then include it
// - Ignore all the elements from this position
// - If the given end interval is in odd position include it and now stop ignoring the elements of the array

struct Interval {
    Interval() {}
    Interval(int l_, int r_) :
      l(l_), r(r_) { }
      
    int l, r;
};


int main() {

    std::vector< Interval > v;
    v.push_back(Interval(1,5));
    v.push_back(Interval(6, 15));
    v.push_back(Interval(20, 21));
    v.push_back(Interval(23, 26));
    v.push_back(Interval(27, 30));
    v.push_back(Interval(35, 40));

    merge_intervals(v, Interval(14, 33));

    return 1;
}


