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
    ifstream fin("promote.in");
    ofstream fout("promote.out");
    int b1, b2, s1, s2, g1, g2, p1, p2;
    fin >> b1 >> b2 >> s1 >> s2 >> g1 >> g2 >> p1 >> p2;
    int news, newg, newp = 0;
    newp = p2 - p1;
    newg = newp + g2 - g1;
    news = newg + s2 - s1;
    fout << news << "\n" << newg << "\n" << newp;
}