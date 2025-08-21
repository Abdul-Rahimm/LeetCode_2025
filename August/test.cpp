// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, vector<int>> adj;

    // Add edges to the adjacency list
    adj[0] = {1, 2};
    adj[1] = {2, 3};
    adj[2] = {3, 4};
    adj[3] = {4, 5};
    adj[4] = {5};

    return 0;
}