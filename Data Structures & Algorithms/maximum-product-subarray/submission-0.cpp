class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int bestProd = nums[0];
        int currMin = nums[0];
        int currMax = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            if (num < 0) {
                swap(currMin, currMax);
            }

            currMax = max(num, currMax * num);
            currMin = min(num, currMin * num);

            bestProd = max(bestProd, currMax);
        }
        return bestProd;
    }
};
