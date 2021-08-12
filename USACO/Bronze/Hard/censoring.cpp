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
    ifstream fin("censor.in");
    ofstream fout("censor.out");
    string S, T;
    fin >> S >> T;
    //int i = 0;
    //string::iterator it;
    //int amnt = count(S.begin(), S.end(), T[0]);
    for (int e = 0; e < S.size() / T.size(); ++e) {
        /*it = find(S.begin(), S.end(), T[0]);
        if (it == S.end()) {
            break;
        }
        else {
            int a = it - S.begin();
            for (int o = 0; o < amnt; ++o) {
                if (S.substr(a, T.size()) == T) {
                    S.erase(a, T.size());                             
                }
                else {
                    
                }
            }
        }*/

        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == T[0] && i <= S.size() - T.size() && S.substr(i, T.size()) == T) {
                S.erase(i, T.size());
            }
        }
    }

    fout << S;
}