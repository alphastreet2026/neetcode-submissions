class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }

        array<int, 26> freq{};
        for (char c : s1) {
            freq[c - 'a']++;
        }

        int n = s1.size();

        int lo = 0;
        array<int, 26> winFreq{};
        for (int i = 0; i < s2.size(); ++i) {
            winFreq[s2[i] - 'a']++;
            if (i - lo + 1 == n) {
                if (winFreq == freq) {
                    return true;
                }
                winFreq[s2[lo] - 'a']--;
                ++lo;
            }
        }
        return false;
    }
};
