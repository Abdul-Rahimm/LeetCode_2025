// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{

    map<int, int> mp;
    unordered_map<int, string> mp2;
    map<int, vector<int>> mp3;
    map<string, vector<pair<int, int>>> mp4;

    mp[10] = 10;
    mp[5];
    mp[20] = 1;

    mp2[3951] = "Abdul Rahim";

    mp3[3951] = {10, 20, 40, 20};
    mp3[1234] = {100, 20};
    mp3[3951].push_back(50);

    mp4["key"] = {{1, 1}, {2, 2}, {3, 3}};
    mp4["key"].push_back(make_pair(4, 4));
    mp4["key"].push_back({5, 5});

    // how to print all the values of a map
    for (auto row : mp)
    {
        int key = row.first;
        int val = row.second;

        cout << key << " " << val << endl;
    }

    // how to check if a key is present in the map or not
    if (mp.find(20) != mp.end())
    {
        cout << "20 has been found" << endl;
    }
    else
    {
        cout << "20 was not found" << endl;
    }
}