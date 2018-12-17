
#include <iostream>
#include <stdlib.h>

struct Blabla {

    Blabla(int a, int b_) {
        ptr = new int[a];
        b = b_;
    }

    ~Blabla() {
        delete []ptr;
    }

    int *ptr;
    int b;
};


int main() {

    int n = 10;
    int *ptr = new int[n];

    ptr[3] = 2;
    std::cout << ptr[3] << "\n";

    free(ptr);

    ptr = (int *)malloc(n * sizeof(int));

    ptr[3] = 2;
    std::cout << ptr[3] << "\n";

    delete []ptr;
    
    return 1;
}