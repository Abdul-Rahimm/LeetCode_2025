class Solution
{
public:
    int BFS(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp, unordered_map<int, int> &nodeLevel)
    {
        queue<TreeNode *> q;

        q.push(root);
        mp[root] = NULL; // root has no father
        int level = 0;

        while (!q.empty())
        {
            int nodes = q.size();

            while (nodes--)
            {
                TreeNode *front = q.front();
                q.pop();
                nodeLevel[front->val] = level;

                if (front->right)
                {
                    q.push(front->right);
                    mp[front->right] = front;
                }
                if (front->left)
                {
                    q.push(front->left);
                    mp[front->left] = front;
                }
            }

            level++;
        }

        return level - 1;
    }
    vector<TreeNode *> BFS(TreeNode *root, int maxLevel, unordered_map<int, int> &nodeLevel)
    {
        queue<TreeNode *> q;
        vector<TreeNode *> leaves;

        q.push(root);
        int level = 0;

        while (!q.empty())
        {
            int nodes = q.size();

            while (nodes--)
            {
                TreeNode *front = q.front();
                q.pop();

                if (nodeLevel[front->val] == maxLevel)
                {
                    leaves.push_back(front);
                }

                if (front->right)
                {
                    q.push(front->right);
                }
                if (front->left)
                {
                    q.push(front->left);
                }
            }

            level++;
        }

        return leaves;
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        unordered_map<TreeNode *, TreeNode *> childToParent;
        unordered_map<int, int> nodeLevel;

        int maxLevel = BFS(root, childToParent, nodeLevel);

        // find out the deepest nodes
        vector<TreeNode *> leaves = BFS(root, maxLevel, nodeLevel);
        int nodes = leaves.size();
        if (nodes == 1)
        {
            return leaves[0];
        }

        // now recursively find out the same parent
        vector<TreeNode *> parent(nodes);

        while (true)
        {
            for (int i = 0; i < nodes; i++)
            {
                parent[i] = childToParent[leaves[i]];
            }

            bool allParentsSame = true;

            for (int i = 1; i < nodes; i++)
            {
                if (parent[i] == parent[i - 1])
                {
                    // cout << "true " << parent[i]->val << " " << parent[i-1]->val << endl;
                    continue;
                }

                // cout << "false " << parent[i]->val << " " << parent[i-1]->val << endl;
                allParentsSame = false;
            }

            if (allParentsSame == true)
                return parent[0];

            leaves = parent;
        }

        return root;
    }
};