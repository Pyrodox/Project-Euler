#include <iostream>
using std::cout;
//answer is 76576500
int main() 
{
    int divisors = 0, count = 1, greatest_divisor_amnt = 0, greatest_amnt_divnum = 0;
    for (int i = 1; i < 99999999; i += count) {
        for (int t = 1; t <= i; ++t) {
            if (i % t == 0) {
                ++divisors;
            }
        }
        ++count;
        if (divisors > greatest_divisor_amnt) {
            greatest_divisor_amnt = divisors;
        }
        divisors = 0;
        if (greatest_divisor_amnt > 500) {
            greatest_amnt_divnum = i;
            break;
        }
    }
    if (greatest_amnt_divnum = 0) {
        cout << "couldn't find";
    }
    cout << greatest_amnt_divnum;
    return 0;
}