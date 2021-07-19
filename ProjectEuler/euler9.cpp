#include <iostream>
#include <math.h>
using std::cout; using std::sqrt; using std::floor;
//answer is 3.1875e+007 or 31875000
int main()
{
    int nums;
    for (double i = 2; i < 1000; ++i) {
        for (double t = 2; t < 1000; ++t) {
            if (sqrt(i * i + t * t) == floor(sqrt(i * i + t * t)) && i + t + sqrt(i * i + t * t) == 1000 && i != t) {
                cout << i * t * sqrt(i * i + t * t);
                nums = i;
                break;
            }
        }
        if (nums == i) {
            break;
        }
    }
    return 0;
}