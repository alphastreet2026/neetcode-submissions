class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                if (dp[i - num]) {
                    dp[i] = true;
                    // break;
                }
            }
        }
        return dp[target];
    }
};
