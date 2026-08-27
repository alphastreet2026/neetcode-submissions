class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int maxLen = 0;
        int left = 0;

        int maxf = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i];
            count[c]++;
            maxf = max(maxf, count[c]);

            int windowLen = i - left + 1;
            if (windowLen - maxf <= k) {
                maxLen = max(maxLen, windowLen);
            } else {
                count[s[left]]--;
                maxf--;
                ++left;
            }
        }
        return maxLen;
    }
};