#include <iostream>
using std::cout; using std::endl;
// answer is 4613732
int main()
{
    int total = 2, first = 1, second = 2;
    for (int i = 3; i <= 4000000; i = first + second) {
        if (i % 2 == 0) {
            total += i;
        }
        first = second;
        second = i;
    }
    cout << total << endl;
    return 0;
}