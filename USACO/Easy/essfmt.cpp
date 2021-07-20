#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

int main() {
    ifstream fin("word.in");
	ofstream fout("word.out");
    ios::sync_with_stdio(false);
    vector<string> v;
    int amt, num;
    string word;
    fin >> amt >> num;
    for (int i = 0; i < amt; i++) {
        fin >> word;
        v.push_back(word);
    }
    int total = 0;
    string pback;
    vector<string> newvec;
    for (int i = 0; i < v.size(); ++i) {
        total += v[i].size();
        pback = v[i];
        while (total < num) {
            if (i + 1 < v.size() && total + v[i + 1].size() <= num) {
                pback += " " + v[i + 1];
                total += v[i + 1].size();
                ++i;
            }
            else {
                break;
            }
        }
        newvec.push_back(pback);
        total = 0;
        pback = "";
    }
    for (auto it = newvec.begin(); it != newvec.end(); ++it) {
        fout << *it << "\n";
    }
}