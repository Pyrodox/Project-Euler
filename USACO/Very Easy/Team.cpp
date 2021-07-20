#include <bits/stdc++.h>
using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    int n, p1, p2, p3, total = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p1 >> p2 >> p3;
        if (p1 + p2 + p3 >= 2) {
            total++;
        }
    }
    cout << total;
}