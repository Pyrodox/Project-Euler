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
            if (v[i] < maxnum) {
                minnum = v[i];
            }
        }
        else {
            if (v[i] < minnum) {
                minnum = v[i];
            }
        }
    }
    int diff = maxnum - minnum;
    v.erase(find(v.begin(), v.end(), maxnum));
    v.erase(find(v.begin(), v.end(), minnum));
    int finalnum;
    if (find(v.begin(), v.end(), minnum) != v.end()) {
        finalnum = maxnum - (2 * minnum);
        cout << minnum << " " << minnum << " " << finalnum;
    }
    else {
        int start = 1, ostart = 1; int end = maxnum - minnum - 1, oend = maxnum - minnum - 1;
        for (int i = 0; i < (oend - ostart) / 2; ++i) {
            if (find(v.begin(), v.end(), start) != v.end() && find(v.begin(), v.end(), end) != v.end()) {
                if (find(v.begin(), v.end(), start + end) != v.end()) {
                    cout << minnum << " " << start << " " << end;
                    break;
                }
            }
            ++start;
            --end;
        }
    }
}