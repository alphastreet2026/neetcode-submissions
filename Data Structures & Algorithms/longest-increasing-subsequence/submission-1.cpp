class Solution {
   public:
    int lengthOfLIS_X(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        tails.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            auto itr = lower_bound(tails.begin(), tails.end(), nums[i]);
            if (itr == tails.end()) {
                tails.push_back(nums[i]);
            } else {
                *itr = nums[i];
            }
        }

        return tails.size();
    }
};
