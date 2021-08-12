#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

void change(vector<int>& v) {
    int c = *(v.begin()); 
    v.erase(v.begin());
    v.push_back(c);
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");
    int N;
    fin >> N;
    vector<int> v;
    int t;
    for (int i = 0; i < N; ++i) {
        fin >> t;
        v.push_back(t);
    }
    int total = INT_MAX, newtotal = 0;
    vector<int> vi;
    vector<int> newv = v;
    for (int i = 0; i < N; ++i) {
        change(newv);
        for (int e = 0; e < N; ++e) {
            newtotal += newv[e] * e;
        }
        if (min(newtotal, total) == newtotal) {
            total = newtotal;
        }
        vi.push_back(newtotal);
        newtotal = 0;
    }
    fout << total;        
}