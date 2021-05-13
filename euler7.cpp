#include <iostream>
using std::cout;
// answer is 104743
int main()
{
    int count = 0;
    bool is_prime = true;
    for (int i = 2; i <= 99999999; ++i) {
        for (int t = 2; t < i; ++t) {
            if (i % t == 0 || i % 2 == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime || i == 2) {
            ++count;
        }
        if (count == 10001) {
            cout << i;
            break;
        }    
        is_prime = true;
    }

    return 0;
}