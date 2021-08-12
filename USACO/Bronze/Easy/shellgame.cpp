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
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int times;
    fin >> times;
    vector<vector<int> > shellvec;
    vector<int> newvec, guessvec;
    int temp;
    for (int i = 0; i < times; ++i) {
        for (int i2 = 0; i2 < 2; ++i2) {
            fin >> temp;
            newvec.push_back(temp);
        }
        fin >> temp;
        guessvec.push_back(temp);
        shellvec.push_back(newvec);
        newvec.clear();
    }
    int total = 0, maxtotal = 0;
    for (int t = 1; t <= 3; ++t) {
        int tempt = t;
        for (int i = 0; i < times; ++i) {
            if (tempt == shellvec[i][0]) {
                tempt = shellvec[i][1]; 
            }
            else if (tempt == shellvec[i][1]) {
                tempt = shellvec[i][0];
            }
            if (guessvec[i] == tempt) {
                ++total;
            }
            maxtotal = max(maxtotal, total);
        }
        total = 0;
    }
    fout << maxtotal;
}