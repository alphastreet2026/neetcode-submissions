class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string_view> words;
        for (auto& word : wordDict){
            words.insert(string_view(word));
        }

        vector<bool> dp(s.size() + 1);
        dp[0] = true;

        string_view sv(s);
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                auto sub = sv.substr(j, i - j);

                if (dp[j] && words.contains(sub)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
