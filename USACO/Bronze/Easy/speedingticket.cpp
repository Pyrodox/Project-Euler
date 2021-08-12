#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

void solver(vector<pair<int, int> > v, vector<int>& vi, int seg)
{
    int total = v[0].first;
    bool breaker = false;
    bool firsttime = true;
    int startval = 1;
    for (int i = 1; i <= 100; ++i) {
        for (int i2 = 0; i2 < seg; ++i2) {
            if (i <= v[0].first) {
                vi.push_back(v[0].second);
                break;
            }
            else {
                for (int i3 = startval; i3 < seg; ++i3) {
                    if (i > total) {
                        if (firsttime) {
                            firsttime = false;
                        }
                        else {
                            i3 += 1;
                            ++startval;
                        }
                        total += v[i3].first;
                    }
                    if (i <= total) {
                        vi.push_back(v[i3].second);
                        breaker = true;
                        break;
                    }
                }
                if (breaker) {
                    breaker = false;
                    break;
                }
            }
        }
       cout << i << " " << vi[i - 1] << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    int segments, cowseg;
    fin >> segments >> cowseg;
    vector<pair<int, int> > full, full2;
    pair<int, int> newpair;
    int tempint, tempint2;
    for (int i = 0; i < segments; ++i) {
        fin >> tempint >> tempint2;
        newpair = make_pair(tempint, tempint2);
        full.push_back(newpair);
    }
    for (int i = 0; i < cowseg; ++i) {
        fin >> tempint >> tempint2;
        newpair = make_pair(tempint, tempint2);
        full2.push_back(newpair);
    }
    int largest = 0;
    vector<int> road1, cow1;
    solver(full, road1, segments);
    solver(full2, cow1, cowseg);
    
    for (int i = 0; i < 100; ++i) {
        if (cow1[i] > road1[i]) {
            largest = max(largest, cow1[i] - road1[i]);
        }
    }
    if (largest < 0) {
        largest = 0;
    }
    fout << largest;
}