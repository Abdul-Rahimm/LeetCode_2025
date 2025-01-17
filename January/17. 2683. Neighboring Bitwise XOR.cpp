class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {

        int n = derived.size();
        if (n == 1)
            return derived[0] == 0;

        vector<int> original;

        for (int i = 0; i < n - 1; i++)
        {
            // if derived[i] == 1 --> means two different numbers
            if (derived[i] == 1)
            {
                if (original.size() == 0)
                {
                    original.push_back(0);
                    original.push_back(1);
                }
                else
                {
                    original.push_back(original[original.size() - 1] ^ 1);
                }
            }
            else
            {
                if (original.size() == 0)
                {
                    original.push_back(1);
                    original.push_back(1);
                }
                else
                {
                    original.push_back(original[original.size() - 1] ^ 0);
                }
            }
        }

        return original[0] ^ original[n - 1] == derived[n - 1];
    }
};