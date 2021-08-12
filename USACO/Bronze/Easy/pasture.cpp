#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

struct rectangle {
    int x1, x2;
    int y1, y2;
};

int xlen(rectangle rec, rectangle rec2) {
    int leftmostx = min(rec.x1, rec2.x1);
    int rightmostx = max(rec.x2, rec2.x2);
    return rightmostx - leftmostx;
}

int ylen(rectangle rec, rectangle rec2) {
    int bottommosty = min(rec.y1, rec2.y1);
    int topmosty = max(rec.y2, rec2.y2);
    return topmosty - bottommosty;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("square.in");
    ofstream fout("square.out");
    rectangle a, b;
    fin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    int square = max(xlen(a, b), ylen(a, b));
    fout << square * square;
}