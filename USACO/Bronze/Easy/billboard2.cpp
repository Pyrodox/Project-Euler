#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LINE__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

struct rectangle {
    int x1, x2;
    int y1, y2;
};

bool subtractneeded(rectangle &lawn, rectangle &feed, string &direction)
{
    if (feed.y2 >= lawn.y2 && feed.y1 <= lawn.y1 && feed.x1 <= lawn.x1 && feed.x2 >= lawn.x2) {
        direction = "";
        return true;
    }
    if (feed.x2 >= lawn.x2 && feed.x1 <= lawn.x1) {
        if (feed.y2 >= lawn.y2 && feed.y1 < lawn.y2) {
            direction = "south";
        }
        else if (feed.y2 > lawn.y1 && feed.y1 <= lawn.y1) {
            direction = "north";
        }
        return true;
    }
    else if (feed.y2 >= lawn.y2 && feed.y1 <= lawn.y1) {
        if (feed.x2 >= lawn.x2 && feed.x1 < lawn.x2) {
            direction = "west";
        }
        else if(feed.x2 >= lawn.x1 && feed.x1 < lawn.x1) {
            direction = "east";
        }
        return true;
    }

    return false;   
}

int area(rectangle a)
{
    int xlen, yhei;
    xlen = a.x2 - a.x1;
    yhei = a.y2 - a.y1;

    return xlen * yhei;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    rectangle lawn, feed;
    string direction = "bruh";
    fin >> lawn.x1 >> lawn.y1 >> lawn.x2 >> lawn.y2 >> feed.x1 >> feed.y1 >> feed.x2 >> feed.y2;
    subtractneeded(lawn, feed, direction);
    
    if (direction == "") {
        fout << 0;
    }
    else if (direction == "west") {
        fout << ((lawn.y2 - lawn.y1) * (feed.x1 - lawn.x1));
    }
    else if (direction == "east") {
        fout << ((lawn.y2 - lawn.y1) * (lawn.x2 - feed.x2));
    }
    else if (direction == "north") {
        fout << ((lawn.x2 - lawn.x1) * (lawn.y2 - feed.y2));
    }
    else if (direction == "south") {
        fout << ((lawn.x2 - lawn.x1) * (feed.y1 - lawn.y1));
    }
    else {
        fout << area(lawn);
    }    
}