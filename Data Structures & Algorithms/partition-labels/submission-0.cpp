class Solution {
   public:
    vector<int> partitionLabels(string s) {
        vector<int> letters(26);

        for (int i = 0; i < s.size(); ++i) {
            letters[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int lo = 0;
        int hi = 0;
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            hi = max(hi, letters[c]);

            if (i == hi){
                int len = hi - lo +1;
                ans.push_back(len);
                lo = i+1;
            }
        }
        return ans;
    }
};
