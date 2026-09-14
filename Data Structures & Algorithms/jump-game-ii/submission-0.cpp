class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int steps = 0;
        int reach = 0;
        int curId = 0;

        for (int i = 0; i < n-1; ++i) {
            reach = max(reach, nums[i] + i);

            if (i == curId){
                ++steps;
                curId = reach;
            }

        }

        return steps;
    }
};
