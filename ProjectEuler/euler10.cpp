#include <iostream>
using std::cout;
//gives wrong answer
int main()
{
    long sum = 10;
    bool is_prime = true;
    for (int i = 5; i < 2000000; i += 2) {
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
            is_prime = false;
        }
        else {
            for (int t = 5; t < i; t += 2) {
                if (i % t == 0) {
                    is_prime = false;
                    break;
                }
            }
        }
        if (is_prime) {
            sum += i;
        }
        is_prime = true;
    }
    cout << sum;
    return 0;
}