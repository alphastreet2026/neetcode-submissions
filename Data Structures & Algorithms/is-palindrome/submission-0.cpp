class Solution {
   public:
    bool isPalindrome(string s) {
        // std::ranges::transform(s, s.begin(), [](unsigned char c) { return std::isalnum(c); });
        // auto view = s | std::views::filter([](unsigned char c) { return std::isalnum(c); });
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) { return std::toupper(c); });
        int lo = 0;
        int hi = s.size();
        cout << "S=" << s << endl;
        while (lo < hi) {
            if (!std::isalnum(s[lo])){
                ++lo;
                continue;
            }
            if (!std::isalnum(s[hi])){
                --hi;
                continue;
            }
            if (s[lo++] != s[hi--]) {
                return false;
            }
        }
        return true;
    }
};
