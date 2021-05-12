#include <iostream>
#include <math.h>
using std::cout; using std::end;
// answer is 6857
int main() 
{
    int factors;
    bool is_prime = true;

    for (int i = 3; i < sqrt(600851475143); ++i) {
        if (600851475143 % i == 0 && i % 2 != 0) {
            for (int t = 3; t < i; ++t) {
                if (i % t == 0) {
                    is_prime = false;
                }
            }
        }
        else {
            is_prime = false;
        }

        if (is_prime == true) {
            factors = i;
        }
        is_prime = true;
    }

    cout << factors;
    return 0;
}