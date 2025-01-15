class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {

        int setBits = __builtin_popcount(num2);

        vector<int> bitPositions; // to see which position bits of num1 are set

        while (num1 > 0)
        {
            bitPositions.push_back(num1 % 2);
            num1 /= 2;
        }

        // first place 1s on the MSB to reduce xor
        // then place the remaining 1s (if any) to most possible low positions

        int sz = max(setBits, (int)bitPositions.size());
        vector<int> bitAns(sz, 0); // to set the bits of ans

        int j = bitPositions.size() - 1;

        while (setBits > 0 and j >= 0)
        {
            if (bitPositions[j] == 1)
            {
                bitAns[j] = 1;
                setBits--;
            }

            j--;
        }

        int i = 0;
        while (setBits > 0)
        {
            while (bitAns[i] == 1)
                i++;

            bitAns[i] = 1;
            setBits--;
        }

        int ans = 0;

        for (int i = 0; i < bitAns.size(); i++)
        {
            ans += bitAns[i] * pow(2, i);
        }

        return ans;
    }
};