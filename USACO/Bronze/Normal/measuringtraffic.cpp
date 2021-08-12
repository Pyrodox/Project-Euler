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
    ifstream fin("traffic.in");
    ofstream fout("traffic.out");
    int N;
    fin >> N;
    vector<string> type;
    vector<int> low, high;
    string tempstring;
    int tempint;
    for (int i = 0; i < N; ++i) {
        fin >> tempstring;
        type.push_back(tempstring);
        fin >> tempint;
        low.push_back(tempint);
        fin >> tempint;
        high.push_back(tempint);
    }
    int low1 = 0, high1 = INT_MAX;
    for (int i = 0; i < N; ++i) {
        if (type[i] == "on") {
            low1 += low[i];
            high1 += high[i];
        }
        else if (type[i] == "none") {
            low[i] = max(low1, low[i]);
            high[i] = min(high1, high[i]);
        }
        else {
            low1 -= high[i];
            high1 -= low[i];
        }
    }
    fout << low1 << " " << high1 << "\n";

    low1 = 0, high1 = INT_MAX;
    for (int i = N - 1; i >= 0; --i) {
        if (type[i] == "off") {
            low1 += low[i];
            high1 += high[i];
        }
        else if (type[i] == "none") {
            low[i] = max(low1, low[i]);
            high[i] = min(high1, high[i]);
        }
        else {
            low1 -= high[i];
            high1 -= low[i];
        }
    }
    fout << low1 << " " << high1 << "\n";
}