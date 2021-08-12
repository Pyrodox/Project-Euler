#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

bool compare(tuple<int, string, int>& first, tuple<int, string, int>& second)
{
    return get<0>(first) < get<0>(second);
}

bool compare2(pair<string, int>& first, pair<string, int>& second)
{
    return first.second > second.second;
}

bool firstval(pair<string, int>& first)
{
    return first.first == "Bessie";
}

bool firstval2(pair<string, int>& first)
{
    return first.first == "Elsie";
}

bool firstval3(pair<string, int>& first)
{
    return first.first == "Mildred";
}

bool compare3(vector<pair<string, int> >& ezclap, vector<pair<string, int> >& oldezclap, int N)
{   
    int highestval = ezclap[0].second;
    if (ezclap[0].first != oldezclap[0].first) {
        return true;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    int N;
    cin >> N;
    int tempint;
    string tempstr;
    vector<tuple<int, string, int> > ez;
    tuple<int, string, int> temptuple;
    for (int i = 0; i < N; ++i) {
        cin >> tempint;
        get<0>(temptuple) = tempint;
        cin >> tempstr;
        get<1>(temptuple) = tempstr;
        cin >> tempint;
        get<2>(temptuple) = tempint;
        ez.push_back(temptuple);
    }
    sort(ez.begin(), ez.end(), compare);
    vector<pair<string, int> > ezclap {{"Bessie", 7}, {"Elsie", 7}, {"Mildred", 7}};
    vector<pair<string, int> > oldezclap {{"Bessie", 7}, {"Elsie", 7}, {"Mildred", 7}};
    int total = 0;
    vector<pair<string, int>>::iterator it;
    for (int i = 0; i < N; ++i) {
        if (get<1>(ez[i]) == "Bessie") {
            it = find_if(ezclap.begin(), ezclap.end(), firstval);
        }
        else if (get<1>(ez[i]) == "Elsie") {
            it = find_if(ezclap.begin(), ezclap.end(), firstval2);
        }
        else if (get<1>(ez[i]) == "Mildred") {
            it = find_if(ezclap.begin(), ezclap.end(), firstval3);
        }
        it->second += get<2>(ez[i]);
        sort(ezclap.begin(), ezclap.end(), compare2);
        for (auto line : ezclap) {
            cout << line.first << " " << line.second << "\n";
        }
        cout << "\n";
        if (compare3(ezclap, oldezclap, N)) {
            ++total;
        }
        oldezclap = ezclap;
    }
    cout << total;
}