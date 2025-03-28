// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define pb push_back
#define all(x) x.begin(), x.end()
#define int long long
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define forn(a, b) for (int i = a; i < b; i++)
#define nl cout << endl;
#define pii pair<int, int>
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mod = 1e9 + 7;

void solve();
int n, m;
vector<vi> arr, cnt, dp;

int recur(int col, int val)
{
    if (col == m)
        return 0;
    if (dp[col][val] != -1)
        return dp[col][val];
    int mini = INT_MAX;
    for (int i = 0; i < 10; i++)
    {
        if (i == val)
            continue;
        int cost = n - cnt[col][i];
        mini = min(mini, recur(col + 1, i) + cost);
    }
    return dp[col][val] = mini;
}

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve()
{
    cin >> n >> m;
    cnt.resize(m, vi(10, 0));
    dp.resize(m, vi(10, -1));
    arr.resize(n, vi(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int col = 0; col < m; col++)
        for (int i = 0; i < n; i++)
            cnt[col][arr[i][col]]++;

    int mini = INT_MAX;
    for (int i = 0; i < 10; i++)
    {
        int cost = n - cnt[0][i];
        mini = min(mini, recur(1, i) + cost);
    }
    cout << mini << endl;
}