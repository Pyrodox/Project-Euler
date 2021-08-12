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
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");

    int N;
    fin >> N;
    string tempstring;
    int tempint;
    vector<string> direction;
    vector<int> moves;
    for (int i = 0; i < N; ++i) {
        fin >> tempstring;
        direction.push_back(tempstring);
        fin >> tempint;
        moves.push_back(tempint);
    }

    int x = INT_MAX, xval = 0, yval = 0, time = 0;
    vector<int> xvals {0}, yvals {0}, times {0};
    for (int i = 0; i < N; ++i) {
        if (direction[i] == "N") {
            for (int t = 0; t < moves[i]; ++t) {
                ++yval;
                ++time;
                for (int e = 0; e < xvals.size(); ++e) {
                    if (xvals[e] == xval && yvals[e] == yval) {
                        x = min(x, abs(time - times[e]));
                    }
                }
                times.push_back(time);
                xvals.push_back(xval);
                yvals.push_back(yval);
            }
        }
        else if (direction[i] == "S") {
            for (int t = 0; t < moves[i]; ++t) {
                --yval;
                ++time;
                for (int e = 0; e < xvals.size(); ++e) {
                    if (xvals[e] == xval && yvals[e] == yval) {
                        x = min(x, abs(time - times[e]));
                    }
                }
                times.push_back(time);
                xvals.push_back(xval);
                yvals.push_back(yval);
            }
        }
        else if (direction[i] == "W") {
            for (int t = 0; t < moves[i]; ++t) {
                --xval;
                ++time;
                for (int e = 0; e < xvals.size(); ++e) {
                    if (xvals[e] == xval && yvals[e] == yval) {
                        x = min(x, abs(time - times[e]));
                    }
                }
                times.push_back(time);
                xvals.push_back(xval);
                yvals.push_back(yval);
            }
        }
        else {
            for (int t = 0; t < moves[i]; ++t) {
                ++xval;
                ++time;
                for (int e = 0; e < xvals.size(); ++e) {
                    if (xvals[e] == xval && yvals[e] == yval) {
                        x = min(x, abs(time - times[e]));
                    }
                }
                times.push_back(time);
                xvals.push_back(xval);
                yvals.push_back(yval);
            }
        }
    }

    if (x != INT_MAX) {
        fout << x << "\n";
    }
    else {
        fout << -1 << "\n";
    }
}