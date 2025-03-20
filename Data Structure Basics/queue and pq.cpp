// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
    priority_queue<int, vi, greater<int>> pq;
    // home 1
    //  f1 2
    //  f2 3 f3 4 f4 5
    //  edges[ [1,2,10],[2,1,10] ]

    vector<vector<int>> edges;

    edges.push_back({1, 2, 10});
    edges.push_back({2, 1, 10});

    edges.push_back({1, 3, 10});
    edges.push_back({3, 1, 10});

    edges.push_back({2, 3, 5});
    edges.push_back({3, 2, 5});

    int u = 1;
    int v = 3;

    // shortest route
}