class Solution {
    int maxSteal(int first, int last, vector<int>& nums){
        int n = nums.size();
        if (first == n){
            return 0; 
        }
        int prev1 = 0;
        int prev2 = nums[first];

        for (int h = first+1; h < last; ++h){
            int p = max(prev2, prev1 + nums[h]);
            prev1 = prev2;
            prev2 = p;
        }
        return prev2;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(maxSteal(0, n-1, nums), maxSteal(1, n, nums));    
    }
};
