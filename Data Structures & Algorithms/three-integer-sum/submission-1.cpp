class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ranges::sort(nums);

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int lo = i + 1;
            int hi = nums.size() - 1;
            // -4 -1 -1 0 1 2 
            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                if (sum < target) {
                    ++lo;
                } else if (sum > target) {
                    --hi;
                } else {
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    int loNum = nums[lo];
                    while (lo < hi && nums[lo] == loNum) {
                        ++lo;
                    }
                    int hiNum = nums[hi];
                    while (lo < hi && nums[hi] == hiNum) {
                        --hi;
                    }
                }
            }
            
        }

        return ans;
    }
};
