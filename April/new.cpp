// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int solve(int a, int b)
{

    // base case
    if (b == 1)
        return a;

    int half = solve(a, b / 2);
    half *= half;

    if (b % 2)
    {
        half *= a;
    }

    return half;
}

int main()
{
    // 2^16

    int a = 2;
    int b = 4;

    cout << solve(a, b) << endl;
}