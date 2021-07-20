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
    vector<int> v;
    int amt, sizev, newi2;
    cin >> amt;
    vector<vector<int> > vvec(amt);
    for (int i = 0; i < amt; ++i) {
        cin >> sizev;
        for (int i2 = 0; i2 < sizev; ++i2) {
            v.push_back(i2 + 1);
        }
        if (sizev % 2 == 0) {
            for (int i2 = 0; i2 < sizev; i2+=2) {
                swap(v[i2], v[i2 + 1]);
            }
        }
        else {
            for (int i2 = 0; i2 < sizev - 1; i2+=2) {
                swap(v[i2], v[i2 + 1]);
            }
            swap(v[v.size() - 1], v[v.size() - 2]);
        }
        vvec[i] = v;
        v.clear();
    }
    for (auto i : vvec) {
        cout << i[0];
        for (auto it = i.begin() + 1; it != i.end(); ++it) {
            cout << " " << *it;
        }
        cout << "\n";
    }
}