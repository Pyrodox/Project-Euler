#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ': '; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

int count2(string s, char val) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == val) {
            ++count;
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");
    int N;
    fin >> N;
    string tempstring;
    vector<string> v1, v2;
    vector<pair<char, int> > v;
    for (int i = 0; i < N; ++i) {
        fin >> tempstring;
        v1.push_back(tempstring);
        fin >> tempstring;
        v2.push_back(tempstring);
    }
    vector<pair<char, int> > v3 = {make_pair('a', 0), make_pair('b', 0), make_pair('c', 0), make_pair('d', 0), make_pair('e', 0), make_pair('f', 0), 
    make_pair('g', 0), make_pair('h', 0), make_pair('i', 0), make_pair('j', 0), make_pair('k', 0), make_pair('l', 0), make_pair('m', 0), make_pair('n', 0), 
    make_pair('o', 0), make_pair('p', 0), make_pair('q', 0), make_pair('r', 0), make_pair('s', 0), make_pair('t', 0), make_pair('u', 0), make_pair('v', 0), 
    make_pair('w', 0), make_pair('x', 0), make_pair('y', 0), make_pair('z', 0)};
    for (int i = 0; i < N; ++i) {
        for (int i2 = 0; i2 < v3.size(); ++i2) {
            v3[i2].second += max(count2(v1[i], v3[i2].first), count2(v2[i], v3[i2].first));
        }
    }
    for (auto c : v3) {
        fout << c.second << "\n";
    } 
}