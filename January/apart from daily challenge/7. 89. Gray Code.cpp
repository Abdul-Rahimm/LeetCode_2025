class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<vector<int>> nums(pow(2, n), vector<int>(n));
        vector<int> ans;

        int change =
            pow(2, n - 1); // change the sequence after these many iterations
        for (int col = 0; col < n; col++)
        {
            int row = 0;

            int count = 0;
            while (row < pow(2, n))
            {
                if (count % 2 == 0)
                {
                    for (int i = 0; i < change; i++)
                    {
                        nums[row][col] = 0;
                        row++;
                    }
                    for (int i = 0; i < change; i++)
                    {
                        nums[row][col] = 1;
                        row++;
                    }
                }
                else
                {
                    for (int i = 0; i < change; i++)
                    {
                        nums[row][col] = 1;
                        row++;
                    }
                    for (int i = 0; i < change; i++)
                    {
                        nums[row][col] = 0;
                        row++;
                    }
                }
                count++;
            }

            change /= 2;
        }

        for (auto row : nums)
        {
            int current = 0;
            int value = pow(2, n - 1);

            for (int i : row)
            {
                current += value * i;
                value /= 2;
            }

            ans.push_back(current);
        }

        return ans;
    }
};