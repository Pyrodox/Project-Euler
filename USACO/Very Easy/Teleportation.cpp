#include <bits/stdc++.h>
using namespace std;

int abs2(int x, int y) {
    if (y - x >= 0) {
        return (y - x);
    }
    else {
        return -1 * (y - x);
    }
}

int main()
{
    ifstream fin("teleport.in");
	ofstream fout("teleport.out");
    ios::sync_with_stdio(false);
    int a, b, c, d;
    fin >> a >> b >> c >> d;

    vector<int> l2{abs2(a, b), abs2(a, c), abs2(a, d)};
    sort(l2.begin(), l2.end());

    if (*l2.begin() == abs2(a, b)) {
        fout << *l2.begin();
    }
    else {
        int total = *l2.begin();
        int main, other;
        if (*l2.begin() == abs2(a, c)) {
            main = c;
            other = d;
        }
        else {
            main = d;
            other = c;
        }
        l2.erase(l2.begin(), ++l2.begin());

        if (abs2(main, b) < abs2(main, other)) {
            total += abs2(main, b);
        }
        else {
            total += abs2(other, b);
        }
        fout << total;
    }

    return 0;
}