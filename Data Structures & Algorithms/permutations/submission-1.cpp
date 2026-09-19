class Solution {
    void dfs(int index, vector<vector<int>>& ans, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            swap(nums[index], nums[i]);
            dfs(index + 1, ans, nums);
            swap(nums[i], nums[index]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        dfs(0, ans, nums);
        return ans;
    }
};
