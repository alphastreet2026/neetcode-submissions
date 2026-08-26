class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        vector<int> freq1(26);
        for (int i=0; i < s.size(); ++i){
            freq1[s[i]-'a']++;
            freq1[t[i]-'a']--;
        }
        for (int count : freq1){
            if (count != 0)
                return false;
        }
        return true;
    }
};
