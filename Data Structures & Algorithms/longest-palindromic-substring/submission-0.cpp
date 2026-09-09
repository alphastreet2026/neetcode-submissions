class Solution {
    int maxLen = 1;
    int start = 0;
    // 123
    // 1234
    void expand(int left, int right, const string& s) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                start = left;
                maxLen = len;
            }
            --left;
            ++right;
        }
        
    }

   public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        for (int i = 0; i < n; ++i) {
            expand(i, i, s);
            expand(i-1, i, s);
        }
        return s.substr(start, maxLen);
    }
};
