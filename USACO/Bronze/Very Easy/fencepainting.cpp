#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int m1, m2;
    vector<int> cd;
    for (int i = c; i <= d; ++i) {
        cd.push_back(i);
    }
    bool overlap = false;
    for (int i = a; i <= b; ++i) {
        if (find(cd.begin(), cd.end(), i) != cd.end()) {
            overlap = true;
        }
    }    
    if (overlap) {
        m1 = min(a, b);
        m1 = min(m1, c);
        m1 = min(m1, d);
        m2 = max(a, b);
        m2 = max(m2, c);
        m2 = max(m2, d);
        cout << m2 - m1;
    }
    else {
        cout << d - c + b - a;
    }
}