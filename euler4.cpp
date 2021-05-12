#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::string; using std::vector; using std::to_string;
// answer is 906609
int main()
{
    string palindrome;
    for (int i = 900; i < 1000; ++i) {
        for (int t = 900; t < 1000; ++t) {
            if(to_string(i * t).size() % 2 == 0) {
                auto possible = to_string(i * t);
                if(possible[0] == possible.back()) {
                    if (possible[1] == possible[possible.length() - 2]) {
                        if (possible[2] == possible[possible.length() - 3]) {
                            palindrome = possible;
                        }
                    }
                }
            }
        }
    }
    cout << palindrome;
    return 0;
}