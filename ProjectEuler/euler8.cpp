#include <iostream>
#include <string>
#define toDigit(c) (c-'0')
using std::cout; using std::string;
//answer is 2091059712 but it's wrong
int main()
{
    long long product = 0;
    string longnum = "1000 digit string here";
    for (int i = 0; i < longnum.size() - 12; ++i) {
        long long bigtotal = toDigit(longnum[i]) * toDigit(longnum[i + 1]) * toDigit(longnum[i + 2]) * toDigit(longnum[i + 3]) 
        * toDigit(longnum[i + 4]) * toDigit(longnum[i + 5]) * toDigit(longnum[i + 6]) * toDigit(longnum[i + 7]) * toDigit(longnum[i + 8])
         * toDigit(longnum[i + 9]) * toDigit(longnum[i + 10]) * toDigit(longnum[i + 11]) * toDigit(longnum[i + 12]);
        if (bigtotal > product) {
             product = bigtotal;
         }
    }
    cout << product;
    return 0;
}