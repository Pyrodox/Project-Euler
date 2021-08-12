#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {cout << __LINE__ << ": "; {x} cout << endl;}}
#define _(x) {cout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t, maxnum = 0, minnum = 0;
    vector<int> v;
    for (int i = 0; i < 7; ++i) {
        cin >> t;
        maxnum = max(maxnum, t);
        v.push_back(t);
    }
    for (int i = 0; i < 7; ++i) {
        if (minnum == 0) {
            minnum = min(v[i], maxnum);
        }
        else {
            minnum = min(v[i], minnum);
        }
    }
    int diff = maxnum - minnum;
    v.erase(find(v.begin(), v.end(), maxnum));
    v.erase(find(v.begin(), v.end(), minnum));
    if (find(v.begin(), v.end(), minnum) != v.end()) {
        diff = maxnum - (2 * minnum);
        cout << minnum << " " << minnum << " " << diff;
    }
    else {
        int minnum2 = 0;
        for (int i = 0; i < 5; ++i) {
            if (minnum2 == 0) {
                minnum2 = min(v[i], maxnum);
            }
            else {
                minnum2 = min(v[i], minnum2);
            }
        }
        cout << minnum << " " << minnum2 << " " << maxnum - minnum - minnum2;
    }
}