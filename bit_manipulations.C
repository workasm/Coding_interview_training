
#include <iostream>
#include <stdlib.h>
#include <bitset>

int highest_bit(int x) {

    int r = 0;
    if(x & 0xFFFF0000) { x >>= 16, r += 16; }
    if(x & 0xFF00) { x >>= 8, r += 8; }
    if(x & 0xF0) { x >>= 4, r += 4; }
    if(x & 0xC) { x >>= 2, r += 2; }
    if(x & 0x2) { r += 1; }
    return r;
}   

int popcount(int x) {

    std::bitset< 32 > bset(x);
    std::cout << bset << "\n";

    x = ((x >> 1) & 0x55555555) + (x & 0x55555555);
    bset = std::bitset< 32 >(x);
    std::cout << bset << "\n";
    x = ((x >> 2) & 0x33333333) + (x & 0x33333333);

    bset = std::bitset< 32 >(x);
    std::cout << bset << "\n";

    x = ((x >> 4) & 0x0f0f0f0f) + (x & 0x0f0f0f0f);
    std::cout << bset << "\n";

    x += x >> 8;
    x += x >> 16;
    x &= 0xff;
    
    bset = std::bitset< 32 >(x);
    std::cout << x << "\n";

    return x;
}

int bitreversal(int x) {

    std::bitset< 32 > bset(x);
    std::cout << bset << "\n";

    int m = 0x55555555;
    x = ((x & m) << 1) | ((x & ~m) >> 1);
    m = 0x33333333;
    x = ((x & m) << 2) | ((x & ~m) >> 2);
    m = 0x0f0f0f0f;
    x = ((x & m) << 4) | ((x & ~m) >> 4);

    bset = std::bitset< 32 >(x);
    std::cout << bset << "\n";

    m = 0x00ff00ff;
    x = ((x & m) << 8) | ((x & ~m) >> 8);
    m = 0x0000ffff;
    x = ((x & m) << 16) | ((x & ~m) >> 16);

    bset = std::bitset< 32 >(x);
    std::cout << bset << "\n";
}

int main() {

    int x = 1231337;
    bitreversal(x);

    return 1;
}

