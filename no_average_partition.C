    
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

struct cmp {
    bool operator()(int a, int b) {
        return (bitrev(a) < bitrev(b));
    }
    int bitrev(int x) {
        int m = 0x55555555;
        x = ((x & m) << 1) | ((x & ~m) >> 1);
        m = 0x33333333;
        x = ((x & m) << 2) | ((x & ~m) >> 2);
        m = 0x0f0f0f0f;
        x = ((x & m) << 4) | ((x & ~m) >> 4);
        m = 0x00ff00ff;
        x = ((x & m) << 8) | ((x & ~m) >> 8);
        m = 0x0000ffff;
        x = ((x & m) << 16) | ((x & ~m) >> 16);
        return x;
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 100, 100, 8, 9, 10, 11, 12};
    int n = sizeof(a) / sizeof(int);
    // get a random shuffle first
    std::random_shuffle(a, a + n);
    for(int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    // now sort the array according to bit rev index
    std::sort(a, a + n, cmp());
    for(int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

