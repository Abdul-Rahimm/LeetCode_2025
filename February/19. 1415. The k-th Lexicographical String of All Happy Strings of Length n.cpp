class Solution
{
public:
    int pos = 0;
    int k;
    string ans = "";
    void recur(string curr, int n)
    {

        if (n == 0)
        {
            pos++;

            if (pos == k)
                ans = curr;

            return;
        }

        // a
        if (curr.empty() or curr.back() != 'a')
            recur(curr + 'a', n - 1);

        // b
        if (curr.empty() or curr.back() != 'b')
            recur(curr + 'b', n - 1);

        // c
        if (curr.empty() or curr.back() != 'c')
            recur(curr + 'c', n - 1);
    }

    string getHappyString(int n, int x)
    {
        k = x;
        recur("", n);

        return ans;
    }
};