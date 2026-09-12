class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int target = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            int dist = target - i;
            if (nums[i] >= dist){
                target = i;
            }
        }
        return target == 0;
    }
};
