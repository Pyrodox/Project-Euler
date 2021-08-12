#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

struct rec {
    int x1, x2;
    int y1, y2;
};

int solveraux(int b1, int b2, int t1, int t2) {
    int newtempv = b2 - b1;
    bool switcher = false;
    if (t1 < b1 && t2 > b2) {
        return newtempv;
    }
    for (int i = b1; i <= b2; ++i) {
        if (i == t1) {
            switcher = true;
            if (t2 >= b2) {
                newtempv = b2 - t1;
            }
            else if (t2 <= b2) {
                newtempv = t2 - t1;
            }
            break;
        }
        else if (i == t2) {
            switcher = true;
            newtempv = t2 - b1;
            break;
        }
    }
    if (!switcher) {
        return 0;
    }

    return newtempv;
}

int solver(rec b, rec t, int& area)
{
    int newx = solveraux(b.x1, b.x2, t.x1, t.x2);
    int newy = solveraux(b.y1, b.y2, t.y1, t.y2);
    area -= newx * newy;

    return area;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    rec b1, b2, t;
    fin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    fin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    fin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
    int area1 = (b1.x2 - b1.x1) * (b1.y2 - b1.y1);
    int area2 = (b2.x2 - b2.x1) * (b2.y2 - b2.y1);
    area1 = solver(b1, t, area1);
    area2 = solver(b2, t, area2);
    fout << area1 + area2;
}