#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


static std::vector< int > g_print;

void permute_rec(std::vector< int >& A, size_t pos)
{
    if(pos >= A.size()) {
        for(auto z : g_print) {
            fprintf(stderr, "%d ", z);
        }
        fprintf(stderr, "\n");
        return;
    }

    for(size_t i = 0; i < A.size(); i++) {

        int z = A[i];
        if(z >= 0) {
            A[i] = -1; // this element is already taken
            g_print[pos] = z;
            permute_rec(A, pos + 1);
            A[i] = z; // put it back..
        }
    }
}

class PermuteObjects {

    // multiplicities of different objects
    // e.g., a a a b b c c c c (rs = {3, 2, 4})
    std::vector< size_t > rs;
    std::vector< char > output;
    size_t n_total = 0, n_perms = 0;

    void permute(size_t pos)
    {
        if(pos >= n_total) {
            fprintf(stderr, "%d: ", ++n_perms);
            for(auto z : output) {
                fprintf(stderr, "%c ", z);
            }
            fprintf(stderr, "\n");
            return;
        }

        for(size_t i = 0; i < rs.size(); i++) {
            if(rs[i] != 0) {
                rs[i]--;
                output[pos] = 'a' + i;
                permute(pos + 1);
                rs[i]++;
            }
        }
    }

public:
    void operator()(const std::vector< size_t >& _rs)
    {
        rs = _rs;
        n_total = 0, n_perms = 0;
        for(auto z : rs) {
            n_total += z;
        }
        output.resize(n_total);
        permute(0);
    }

};


int main()
{
    PermuteObjects oo;
    oo({2,3,1});
    return 0;
}
