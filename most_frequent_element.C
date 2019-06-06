
/**
How would you find out a word with maximum number of occurences in a big book ..like big big book..

This is a tricky question and is expensive to solve using traditional methods.
One alternative method is to use a large Array. Each element of this Array is a pointer to string.
Now read each string from the book. Take a random no in range 0 to Max_Array_Size. Replace the existing Array[randomNo] with the recently read string.
At the end of reading all words from book, check the array and find the string which is occuring maximum times.

I was asked similar question and argued that the solution will not work. Interviewer explained the following
1. Algorithm most of the times work. I forgot the algorithm name.
2. Array size has to be of certain size according to a formula. I don't remember that
3. The algorithm is very fast and efficient.
4. Can we used in search type applications like google/bing etc where you don't need 100% accurate results.
5. If a word occurs many times in the book, there is higher probability that the word is present at multiple places in the Array.

**/