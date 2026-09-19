class Solution {
void dfs(vector<int>& subset, vector<vector<int>>& ans, vector<bool>& used, vector<int>& nums){
    if (subset.size() == nums.size()){
        ans.push_back(subset);
        return;
    }

    for (int i = 0; i < nums.size(); ++i){
        if (used[i]){
            continue;
        }
        subset.push_back(nums[i]);
        used[i] = true;
        dfs(subset, ans, used, nums);
        subset.pop_back();
        used[i] = false;
    }

}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        vector<bool> used(nums.size());

        dfs(subset, ans, used, nums);
        return ans;

    }
};
