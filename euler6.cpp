#include <iostream>
using std::cout;
// answer is 25164150
int main() {
    int count_squares = 0; int reg_count = 0;
    for (int i = 1; i <= 100; ++i) {
        count_squares += i * i;
        reg_count += i;
    }
    cout << reg_count * reg_count - count_squares;
    
    return 0;
}