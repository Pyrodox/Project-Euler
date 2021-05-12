#include <iostream>
#include <vector>
using std::cout; using std::endl; using std::vector;
// answer is 4613732
int main()
{
    int total = 2, first = 1, second = 2;
    vector<int> fib_seq;
    fib_seq.push_back(first);
    fib_seq.push_back(second);
    for (int i = 3; i <= 4000000; i = fib_seq[fib_seq.size() - 1] + fib_seq[fib_seq.size() - 2]) {
        if (i % 2 == 0) {
            total += i;
        }
        fib_seq.push_back(i);
    }
    cout << total << endl;
    return 0;
}