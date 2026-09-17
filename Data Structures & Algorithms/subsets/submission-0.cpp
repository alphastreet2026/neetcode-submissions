class Solution {
    void dfs(int start, vector<int>& subset, vector<vector<int>>& ans, vector<int>& nums){
        ans.push_back(subset);

        for (int i = start; i < nums.size(); ++i){
            subset.push_back(nums[i]);
            dfs(i+1, subset, ans, nums);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subset;

        dfs(0, subset, ans, nums);
        return ans;
    }
};
