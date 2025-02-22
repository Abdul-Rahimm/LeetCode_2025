/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements
{
public:
    unordered_set<int> st;
    void recur(TreeNode *root, int value)
    {
        if (root == NULL)
            return;

        root->val = value;

        // left
        recur(root->left, 2 * value + 1);

        // right
        recur(root->right, 2 * value + 2);
    }
    void BFS(TreeNode *root)
    {
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            st.insert(curr->val);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    FindElements(TreeNode *root)
    {
        recur(root, 0);

        BFS(root);
    }

    bool find(int target)
    {
        if (st.find(target) != st.end())
            return true;

        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */