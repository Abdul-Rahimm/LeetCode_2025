class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        bool increasing = false, decreasing = false;

        int n = nums.size();
        int ans = 1;
        int curr = 1;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (increasing == true) {
                    increasing = false;
                    curr = 2;
                } else {
                    ans = max(ans, ++curr);
                }

                decreasing = true;
            } else if (nums[i] < nums[i + 1]) {
                if (decreasing == true) {
                    decreasing = false;
                    curr = 2;
                } else {
                    ans = max(ans, ++curr);
                }

                increasing = true;
            } else {
                increasing = false;
                decreasing = false;
                curr = 1;
            }
        }

        return ans;
    }
};