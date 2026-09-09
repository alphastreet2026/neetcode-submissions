

class Solution {
    int expand(int left, int right, string& s){
        int cnt = 0;
        while(left >=0 && right < s.size() && s[left] == s[right]){
            ++cnt;
            --left;
            ++right;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i=0; i < s.size(); ++i){
            cnt += expand(i, i, s);
            cnt += expand(i-1, i, s);
        }
        return cnt;
    }
};