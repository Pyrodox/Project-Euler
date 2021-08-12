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
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int amntofcows;
    fin >> amntofcows;
    int temp;  
    vector<int> positions;
    vector<int> cowids;
    for (int i = 0; i < amntofcows; ++i) {
        fin >> temp;
        positions.push_back(temp); 
    }
    for (int i = 0; i < amntofcows; ++i) {
        fin >> temp;
        cowids.push_back(temp);
    }
    vector<int> output;
    output.resize(amntofcows);
    for (int i = 0; i < amntofcows; ++i) {
        output[i] = cowids[positions[i] - 1];
    }
    vector<int> output2;
    output2.resize(amntofcows);
    for (int i = 0; i < amntofcows; ++i) {
        output2[i] = output[positions[i] - 1];
    }
    vector<int> output3;
    output3.resize(amntofcows);
    for (int i = 0; i < amntofcows; ++i) {
        output3[i] = output2[positions[i] - 1];
    }
    for (auto i : output3) {
        fout << i << "\n";
    }
}