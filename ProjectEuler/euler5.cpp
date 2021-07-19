#include <iostream>
using std::cout;
//answer is 232792560
int main()
{
    int count = 0, a = 0;
    while (count != 20) {
        for (int t = 70; t < 999999999; ++t) {
            if (count == 20) {
                break;
            }
            a = t;
            for (int i = 1; i <= 20; ++i) {
                if (t % i == 0) {
                    ++count;
                    if (count == 20) {
                        break;
                    }
                }
                else {
                    count = 0;
                    break;
                }
                if (count == 20) {
                    break;
                }
            }
        }
    }
    cout << a;
    return 0;
}