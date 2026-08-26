class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& str : strs){
            string key = str;
            ranges::sort(key);
            groups[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto [key, strings] : groups){
            ans.push_back(strings);
        }
        return ans;

    }
};
