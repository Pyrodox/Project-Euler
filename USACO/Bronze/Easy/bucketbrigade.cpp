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
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");
    vector<string> v;
    string x;
    for (int i = 0; i < 10; ++i) {
        getline(fin, x);
        v.push_back(x);
    }
    int bposx = 0, bposy = 0;
    bool breaktrue0 = false, addtrue = false, addtrue2 = false;
    for (int i = 0; i < 10; ++i) {//iterate through each string in the vector
        for (auto it = v[i].begin(); it != v[i].end(); ++it) {//iterate through each char in that string
            if (*it == 'B') {//if the char is B
                bposy = i;//setting y equal to vector found in
                bposx = it - v[i].begin();//setting x to position found in string
                for (int i2 = bposx; i2 < 10; ++i2) {//finding x
                    if (v[i][i2] == 'L') {//found L
                        breaktrue0 = true;
                        break;
                    }
                    else if (v[i][i2] == 'R' && find(v[i].begin() + i2, v[i].end(), 'L') != v[i].end()) {//found R
                        addtrue = true;
                        breaktrue0 = true;
                        break;
                    }
                }
                if (!breaktrue0) {
                    for (int i2 = bposx; i2 >= 0; --i2) {
                        if (v[i][i2] == 'L') {
                            breaktrue0 = true;
                            break;
                        }
                        else if (v[i][i2] == 'R' && find(v[i].begin(), v[i].begin() + i2, 'L') != v[i].begin() + i2) {
                            addtrue = true;
                            breaktrue0 = true;
                            break;
                        }
                    }
                }
                if (breaktrue0) {
                    break;
                }
                for (int i3 = bposy; i3 < 10; ++i3) {//finding y
                    if (v[i3][bposx] == 'L') {//found L
                        breaktrue0 = true;
                        break;
                    }
                    else if (v[i3][bposx] == 'R') {//found R
                        for (int i4 = i3; i4 < 10; ++i4) {
                            if (v[i4][bposx] == 'L') {
                                addtrue2 = true;
                                breaktrue0 = true;
                                break;
                            }
                        }
                        if(breaktrue0) {
                            break;
                        }
                    }
                    if (breaktrue0) {
                        break;
                    }
                }
                if (!breaktrue0) {
                    for (int i5 = bposy; i5 >= 0; --i5) {
                        if (v[i5][bposx] == 'L') {
                            breaktrue0 = true;
                            break;
                        }
                        else if (v[i5][bposx] == 'R') {
                            for (int i6 = i5; i6 >= 0; --i6) {
                                if (v[i6][bposx] == 'L') {
                                    breaktrue0 = true;
                                    addtrue2 = true;
                                    break;
                                }
                            }
                        } 
                    }
                }
                if (breaktrue0) {
                    break;
                }
            }
            if (breaktrue0) {
                break;
            }
        }
        if (breaktrue0) {
            break;
        }
    }
    int lposx = 0, lposy = 0;
    bool breaktrue = false;
    for (int i = 0; i < 10; ++i) {
        for (auto it = v[i].begin(); it != v[i].end(); ++it) {
            if (*it == 'L') {
                lposy = i;
                lposx = it - v[i].begin();
                breaktrue = true;
                break;
            }
        }
        if (breaktrue) {
            break;
        }
    }
    int total = 0;
    total += abs(lposx - bposx);
    total += abs(lposy - bposy);
    if (addtrue || addtrue2) {
        fout << total + 1;
    }
    else {
        fout << total - 1;
    }
}