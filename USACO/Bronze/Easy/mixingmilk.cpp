#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

void pour(int& firstbuc, int& secondbuc, int secondcap)
{
    if (firstbuc + secondbuc <= secondcap) {
        secondbuc += firstbuc;
        firstbuc = 0;
    }
    else {
        int addamnt = secondbuc + firstbuc - secondcap;
        secondbuc = secondcap;
        firstbuc = addamnt;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    int b1, b2, b3;
    int c1, c2, c3;
    fin >> c1 >> b1 >> c2 >> b2 >> c3 >> b3;
    for (int i = 0; i < 33; ++i) {
        pour(b1, b2, c2);
        pour(b2, b3, c3);
        pour(b3, b1, c1);
    }
    pour(b1, b2, c2);
    fout << b1 << "\n" << b2 << "\n" << b3;
}