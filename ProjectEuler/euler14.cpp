#include <iostream>
#include <vector>
#include <algorithm>
using std::cout; using std::vector; using std::find;

int main()
{
    int count = 1, finalnum = 0, longest_chain = 0, biggestseq = 0;
    vector<int> store{}, countvec{};
    for (int i = 100001; i < 1000000; i += 2) {
        finalnum = i;
        while (finalnum != 1) {
            ++count;
            if (finalnum % 2 == 0) {
                finalnum /= 2;
            }
            else {
                finalnum = 3 * finalnum + 1;
                finalnum /= 2;
                ++count;
            }
            if(find(store.begin(), store.end(), finalnum) != store.end()) {
                // add index of countvec to count and break
            }
        }
        if (count > longest_chain) {
            longest_chain = count;
            biggestseq = i;
        }
        store.push_back(i); countvec.push_back(count);
        count = 1;
    }
    cout << biggestseq;
    return 0;
}