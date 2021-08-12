#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

vector<char> split(vector<char> v, string s)
{
    for (auto c : s) {
        v.push_back(c);
    }

    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    int M, N, K;
    fin >> M >> N >> K;
    string tempchar;
    vector<char> tempstring;
    vector<vector<char> > collectionofstrings;
    for (int i = 0; i < M; ++i) {
        fin >> tempchar;
        collectionofstrings.push_back(split(tempstring, tempchar));
        tempstring.clear();
    }
    int amntoflines = K * M;
    for (int i = 0; i < M; ++i) {
        for (int i2 = 0; i2 < K; ++i2) {
            for (int t = 0; t < N; ++t) {
                for (int i3 = 0; i3 < K; ++i3) {
                    fout << collectionofstrings[i][t];
                }
            }
            fout << "\n";
        }
    }
}