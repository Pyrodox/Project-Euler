#include <bits/stdc++.h>
#define DEBUG false
#define OJ_DEBUG
#define $(x) {if (DEBUG) {fout << __LIME__ << ": "; {x} fout << endl;}}
#define _(x) {fout << #x << " = " << x << " ";}
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;

bool compare(tuple<int, int, int> i1, tuple<int, int, int> i2)
{
    return get<0>(i1) < get<0>(i2);
}

bool if_avail(pair<int, string> is)
{
    return is.second == "avail";
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int amntofcows;
    fin >> amntofcows;
    vector<tuple<int, int, int> > collection;
    int temp1, temp2i, temp3; //temp1 is the start time, temp2i is the end time, and temp3 is the amount of buckets needed for that cow
    tuple<int, int, int> temp2;
    for (int i = 0; i < amntofcows; ++i) {
        fin >> temp1;
        fin >> temp2i;
        fin >> temp3;
        temp2 = make_tuple(temp1, temp2i, temp3);
        collection.push_back(temp2);
    }
    //made a tuple and made a vector of that type of tuple and appended all the values inputted into that vector
    sort(collection.begin(), collection.end(), compare); //sorted so the start times would be in descending order, so 1 to 100 for example
    /*cout << "\n\n";
    for (auto c : collection) {
        cout << get<0>(c) << " " << get<1>(c) << " " << get<2>(c) << "\n";
    }*/
    vector<pair<int, string> > buckets; /*vector of pairs, the int is the end time when the bucket is free for use, and the string is if the bucket is
    available or not*/
    int totalbuckets = 0; //totalbuckets is the final value where the program outputs how many buckets were used in total
    for (int i = 1; i <= 1000; ++i) { //iterating through all possible start and end times: determining if the vector buckets needs ot be adjusted or not
        for (int i1 = 0; i1 < buckets.size(); ++i1) { //iterating through all current buckets
            if (buckets[i1].second == "unavail" && i == buckets[i1].first + 1) { //checking if it's their time to be available or not
                buckets[i1].second = "avail"; //then making them available if that's the case
            }
        }
        for (int t = 0; t < collection.size(); ++t) { //iterating through all lines of input
            if (i == get<0>(collection[t])) { //checking for the next start time
                if (find_if(buckets.begin(), buckets.end(), if_avail) == buckets.end() || buckets.empty()) { //checking if no buckets available in general
                    totalbuckets += get<2>(collection[t]); //if no buckets are available, then add the amount of buckets to the final answer
                    for (int e = 0; e < get<2>(collection[t]); ++e) { //iterating through the that line of input's amount of buckets
                        buckets.push_back(make_pair(get<1>(collection[t]), "unavail")); //adding those buckets to the vector using their end time and marking them as unavail
                    }
                }
                else { //else means that there are some buckets available
                    if (get<2>(collection[t]) <= count_if(buckets.begin(), buckets.end(), if_avail)) { //if amount of buckets needed less than or equal to amount of buckets that say "avail" in the buckets vector
                        int fixed = 0; //amount of changed buckets before the for loop changing buckets to unavail and changing their end times
                        for (int r = 0; r < buckets.size(); ++r) { //iterating through all buckets
                            if (buckets[r].second == "avail") { //checking for avail buckets to use
                                ++fixed; //adding to fixed, meaning found bucket to change
                                buckets[r].second = "unavail"; //indicating that the bucket is used
                                buckets[r].first = get<1>(collection[t]); //changing end time of the bucket, when it almost becomes available again
                            }
                            if (fixed == get<2>(collection[t])) { //enough changed buckets
                                break; //so break
                            }
                        }
                    }
                    else { //else if there are less available buckets than needed
                        totalbuckets += get<2>(collection[t]) - count_if(buckets.begin(), buckets.end(), if_avail); //add to the amount of buckets used by subtracting buckets needed with buckets available
                        int tempval = get<2>(collection[t]) - count_if(buckets.begin(), buckets.end(), if_avail);
                        for (int r = 0; r < buckets.size(); ++r) { //iterating through all the bcukets
                            if (buckets[r].second == "avail") { //checking if a bucket is available, and if so, then: 
                                buckets[r].second = "unavail"; //change it to unavailable
                                buckets[r].first = get<1>(collection[t]); //change the end time of the bucket (around when it becomes available again)
                            }
                        }
                        for (int o = 0; o < tempval; ++o) {
                            buckets.push_back(make_pair(get<1>(collection[t]), "unavail"));
                        }
                    }
                }
            }
        }
    }
    fout << totalbuckets; //the final answer
}