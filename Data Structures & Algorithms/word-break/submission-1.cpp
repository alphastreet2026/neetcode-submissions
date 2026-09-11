class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string sub = s.substr(j, i - j);

                if (dp[j] && words.contains(sub)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
