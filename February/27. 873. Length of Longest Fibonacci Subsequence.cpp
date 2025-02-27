class Solution
{
public:
    map<vector<int>, int> mp;

    int recur(int i, vector<int> &arr, int last, int prevToLast, int size)
    {
        if (mp.find({i, last, prevToLast, size}) != mp.end())
            return mp[{i, last, prevToLast, size}];

        if (i >= arr.size())
        {
            return size > 2 ? size : -1;
        }

        int left = 0;
        if (last == -1)
            left = recur(i + 1, arr, arr[i], prevToLast, size + 1);
        else if (prevToLast == -1)
        {
            left = recur(i + 1, arr, arr[i], last, size + 1);
        }
        else
        {
            if (last + prevToLast == arr[i])
            {
                left = recur(i + 1, arr, arr[i], last, size + 1);
            }
        }

        int right = recur(i + 1, arr, last, prevToLast, size);

        return mp[{i, last, prevToLast, size}] = max(left, right);
    }
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> temp;
        int ans = recur(0, arr, -1, -1, 0);

        return ans == -1 ? 0 : ans;
    }
};