

#include <iostream>
#include <vector>

void div_periodic(int num, int denom) {

    int div = num / denom;
    int mod = num % denom;

    printf("%d.", div); // print integer part
    num = mod;

    int niters = 100;
    std::vector< int > digits;
    int istart = -1, ibeyond = 0; // period is [istart; ibeyond)

    while(niters--) {

    num *= 10; // num is always smaller than denom

    int n_zeros = 0;
    while(num < denom) { // add the required number of zeros
        num *= 10; n_zeros++;
        digits.push_back(0); // 
    }

    div = num / denom; // div is always a single digit
    mod = num % denom;

    digits.push_back(div); // digits hold digits
    printf("%d", div);
//     printf("n_zeros: %d; div: %d; mod: %d\n", n_zeros, div, mod);
    num = mod;
    if(num == 0)
        break;
    }
    printf("\n");
}


int main() {

    div_periodic(11, 3);
    return 1;

}