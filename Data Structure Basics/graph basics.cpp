// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{

    unordered_map<string, vector<pair<string, int>>> adj;

    adj["khi"] = {make_pair("isl", 10), make_pair("lhr", 20)};
    adj["isl"] = {{"khi", 10}, {"hyd", 50}};
    adj["lhr"] = {{"khi", 20}, {"pwr", 60}};
    adj["hyd"] = {{"isl", 50}};
    adj["pwr"] = {{"lhr", 60}};
    adj["skl"] = {{"lhr", 5}};

    adj["lhr"].push_back({"skl", 5});

    for (auto row : adj)
    {
        cout << row.first << " | ";
        for (pair<string, int> city : row.second)
        {
            cout << city.first << " " << city.second << " , ";
        }
        cout << endl;
    }
}