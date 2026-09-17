class Solution {
    void dfs(int start, int sum, vector<int>& subset, vector<vector<int>>& ans, vector<int>& nums, int target) {
        if (sum == target){
            ans.push_back(subset);
            return;
        }
        if (sum > target){
            return;
        }

        for (int i = start; i < nums.size(); ++i){
            subset.push_back(nums[i]);
            dfs(i,  sum+nums[i], subset, ans, nums, target);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> subset;

        dfs(0, 0, subset, ans, nums, target);
        return ans;
    }
};

// class Solution {
//     void dfs(int index, vector<int>& current, vector<vector<int>>& res, vector<int>& candidates, int target){
//         if (target == 0){
//             res.push_back(current);
//             return;
//         }
//         if (target < 0){
//             return;
//         }

//         for (int i = index; i < candidates.size(); ++i){
//             current.push_back(candidates[i]);
//             dfs(i, current, res, candidates, target - candidates[i]);
//             current.pop_back();
//         }

//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> res;
//         vector<int> current;
//         dfs(0, current, res, candidates, target);
//         return res;
//     }
// };