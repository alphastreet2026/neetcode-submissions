class Solution {
public:
    int rob(vector<int>& nums) {
        int maxProfit = 0;
        int n = nums.size();
        if (n <= 1){
            return nums[0];
        }
        
        int prev1 = 0;
        int prev2 = nums[0];
        
        for (int i = 1; i < n; ++i){
            int p = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = p;
        }
        return prev2;
    }
};
