
Given a stream of unsorted integers, find the median element in sorted order at any given time. So, we will be receiving a continuous stream of numbers in some random order and we don?t know the stream length in advance. Write a function that finds the median of the already received numbers efficiently at any time. We will be asked to find the median multiple times. Just to recall, median is the middle element in an odd length sorted array, and in the even case it?s the average of the middle elements.

3 4 5 7 9
# of elements is odd: median is 5

3 4 5 6 7 9
# of elements is even: median is (5 + 6) / 2

size of max heap = size of min heap (+1)

hence elements in max heap are <= then elements in min heap 

We will use 2 heaps simultaneously, a max-heap and a min-heap with 2 requirements. The first requirement is that the max-heap contains the smallest half of the numbers and min-heap contains the largest half. So, the numbers in max-heap are always less than or equal to the numbers in min-heap. Let?s call this the order requirement. The second requirement is that, the number of elements in max-heap is either equal to or 1 more than the number of elements in the min-heap. So, if we received 2N elements (even) up to now, max-heap and min-heap will both contain N elements. Otherwise, if we have received 2N+1 elements (odd), max-heap will contain N+1 and min-heap N. Let?s call this the size requirement.

The heaps are constructed considering the two requirements above. Then once we?re asked for the median, if the total number of received elements is odd, the median is the root of the max-heap. If it?s even, then the median is the average of the roots of the max-heap and min-heap. Let?s now analyse why this approach works, and how we construct the heaps.

We will have two methods, insert a new received number to the heaps and find median. The insertion procedure takes the two requirements into account, and it?s executed every time we receive a new element. We take two different approaches depending on whether the total number of elements is even or odd before insertion.
 
Let?s first analyze the size requirement during insertion. In both cases we insert the new element to the max-heap, but perform different actions afterwards. In the first case, if the total number of elements in the heaps is even before insertion, then there are N elements both in max-heap and min-heap because of the size requirement. After inserting the new element to the max-heap, it contains N+1 elements but this doesn?t violate the size requirement. Max-heap can contain 1 more element than min-heap. In the second case, if the number of elements is odd before insertion, then there are N+1 elements in max-heap and N in min-heap. After we insert the new element to the max-heap, it contains N+2 elements. But this violates the size constraint, max-heap can contain at most 1 more element than min-heap. So we pop an element from max-heap and push it to min-heap. The details will be described soon.