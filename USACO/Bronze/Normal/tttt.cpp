#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

void addsolo(vector<char>& solo, char c1, char c2, char c3)
{
    if (c1 == c2 && c1 == c3 && find(solo.begin(), solo.end(), c1) == solo.end()) {
        solo.push_back(c1);
    }
}

void addteam(vector<pair<char, char> >& team, char c1, char c2, char c3) 
{
    if (c1 == c2 && c1 != c3) {
        if (find(team.begin(), team.end(), make_pair(c1, c3)) == team.end()
        && find(team.begin(), team.end(), make_pair(c3, c1)) == team.end()) {
            team.push_back(make_pair(c1, c3));
        }
    }
    else if (c1 == c3 && c1 != c2) {
        if (find(team.begin(), team.end(), make_pair(c1, c2)) == team.end()
        && find(team.begin(), team.end(), make_pair(c2, c1)) == team.end()) {
            team.push_back(make_pair(c1, c2));
        }
    }
    else if (c3 == c2 && c1 != c3) {
        if (find(team.begin(), team.end(), make_pair(c1, c3)) == team.end()
        && find(team.begin(), team.end(), make_pair(c3, c1)) == team.end()) {
            team.push_back(make_pair(c1, c3));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("tttt.in");
    ofstream fout("tttt.out");

    string tempstring;
    vector<string> v;
    for (int i = 0; i < 3; ++i) {
        fin >> tempstring;
        v.push_back(tempstring);
    }

    vector<char> solo;
    for (int i = 0; i < 3; ++i) {
        addsolo(solo, v[i][0], v[i][1], v[i][2]);
    }
    for (int i = 0; i < 3; ++i) {
        addsolo(solo, v[0][i], v[1][i], v[2][i]);
    }
    addsolo(solo, v[0][0], v[1][1], v[2][2]);
    addsolo(solo, v[0][2], v[1][1], v[0][2]);
    
    vector<pair<char, char> > team;
    for (int i = 0; i < 3; ++i) {
        addteam(team, v[i][0], v[i][1], v[i][2]);
    }
    for (int i = 0; i < 3; ++i) {
        addteam(team, v[0][i], v[1][i], v[2][i]);
    }
    addteam(team, v[0][0], v[1][1], v[2][2]);
    addteam(team, v[0][2], v[1][1], v[2][0]);

    fout << solo.size() << "\n";
    fout << team.size();
}