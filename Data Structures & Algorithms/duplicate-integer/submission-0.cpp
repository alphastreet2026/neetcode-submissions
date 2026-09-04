class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums){
            if(!numSet.insert(num).second){
                return true;
            }
        }
        return false;
    }
};