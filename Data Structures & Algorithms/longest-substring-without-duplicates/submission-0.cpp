class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int maxLen = 0;
        int lo = 0;
        for (int i = 0; i < s.size(); ++i){
            char c = s[i];
            while (chars.contains(c)){
                chars.erase(s[lo++]);
            }
            chars.insert(c);
            maxLen = max(maxLen, i-lo +1);
        }
        return maxLen;
    }
};
