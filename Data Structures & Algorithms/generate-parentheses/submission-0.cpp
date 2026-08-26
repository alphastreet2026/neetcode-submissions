class Solution {
    void dfs(vector<string>& ans, int left, int right, string str) {
        if (left == 0 && right == 0) {
            ans.push_back(str);
            return;
        }
        if (left > 0) {
            
            dfs(ans, left - 1, right, str + "(");
        }

        if (right > left) {
            dfs(ans, left, right - 1, str + ")");
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, n, n, "");
        return ans;
    }
};
