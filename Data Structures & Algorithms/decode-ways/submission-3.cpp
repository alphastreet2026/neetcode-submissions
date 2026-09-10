class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') {
            return 0;
        }

        
        int prev1 = 1;
        int prev2 = 1;

        for (int i = 2; i <= n; ++i) {
            int curr = 0;
            int c = s[i-1] - '0';
            if (c != 0) {
                curr = prev2;
            }

            int t = 10 * (s[i - 2] - '0') + c;
            if (t <= 26 && t >= 10) {
                curr += prev1;
            }

            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};
