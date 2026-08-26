class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1){
            return nums.size();
        }
        ranges::sort(nums);

        int maxLen = 1;

        int prev = nums[0];
        int currLen = 1;
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] == prev){
                continue;
            }
            if (nums[i] - prev == 1){
                currLen++;
            }else{
                currLen = 1;
            }
            prev = nums[i];
            maxLen = max(maxLen, currLen); 
        }
        return maxLen;
    }
};
