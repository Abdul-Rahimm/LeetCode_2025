// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

map<int, vector<int>> mp;

void recur(TreeNode *root, int level)
{
    if (root == NULL)
        return;

    vector<int> nodes = mp[level];
    for (int i : nodes)
        cout << i << " ";
    cout << endl;

    root->val = nodes[nodes.size() - 1];
    // mp[level].erase(root->val);
    mp[level].pop_back();

    recur(root->left, level + 1);
    recur(root->right, level + 1);
}
TreeNode *recoverFromPreorder(string traversal)
{
    int n = traversal.size();

    int i = 0;
    while (i < n)
    {
        int dashes = 0;
        while (i < n and traversal[i] == '-')
        {
            i++;
            dashes++;
        }

        mp[dashes].push_back(traversal[i] - '0');
        i++;
    }

    for (auto &row : mp)
        reverse(row.second.begin(), row.second.end());

    for (auto &row : mp)
    {
        cout << row.first << " : ";
        for (int i : row.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    TreeNode *root = new TreeNode(1);
    recur(root, 0);

    return root;
}

int main()
{
    TreeNode *ans = recoverFromPreorder("1-2--3--4-5--6--7");
}