#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("teleport.in");
	ofstream fout("teleport.out");
    ios::sync_with_stdio(false);
    int a, b, c, d;
    fin >> a >> b >> c >> d;

    vector<int> l2{abs(a - b), abs(a - c), abs(a - d)};
    sort(l2.begin(), l2.end());

    if (*l2.begin() == abs(a - b)) {
        fout << *l2.begin();
    }
    else {
        int total = *l2.begin();
        int main, other;
        if (*l2.begin() == abs(a - c)) {
            main = c;
            other = d;
        }
        else {
            main = d;
            other = c;
        }

        if (abs(main - b) < abs(main - other) && abs(other - b) > abs(main - b)) {
            total += abs(main - b);
        }
        else {
            total += abs(other - b);
        }
        if (abs(a - b) < total) {
            fout << abs(a - b);
        }
        else {
            fout << total;
        }
    }
}