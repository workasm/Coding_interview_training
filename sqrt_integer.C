
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>


    unsigned isqrt(unsigned x)
    {  
        unsigned root, sh = 1 << 30;
        while (sh > x) sh >>= 2;
        while (sh != 0) {
            if (x >= root + sh) {
                x -= root + sh;
                root += sh << 1;
            }  
            root >>= 1;
            sh >>= 2;
        }  
        return root;  
    }
