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
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");
    int x, y;
    fin >> x >> y;
    int ogx = x;
    if (x == y) {
        return 1;
    }
    int newdist = 0;
    int newx;
    for (int i = 1; i <= INT_MAX; i *= -2) {
        newx = ogx + i;
        int oldx = x;
        if (i > 0) {
            for (int t = oldx; t < newx; ++t) {
                ++newdist;
                ++x;
                if (y == x) {
                    break;
                }
            }
        }
        else {
            for (int t = oldx; t > newx; --t) {
                ++newdist;
                --x;
                if (y == x) {
                    break;
                }
            }
        }
        if (y == x) {
            break;
        }
    }
    fout << newdist;
}