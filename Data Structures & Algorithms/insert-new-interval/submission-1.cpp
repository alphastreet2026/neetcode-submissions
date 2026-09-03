class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int i = 0;
        for (auto& interval : intervals) {
            if (interval[0] < newInterval[0]) {
                ans.push_back(interval);
            } else {
                break;
            }
            ++i;
        }

        if (!ans.empty() && ans.back()[1] >= newInterval[0]) {
            ans.back()[1] = max(ans.back()[1], newInterval[1]);
        } else {
            ans.push_back(newInterval);
        }
        cout << i << endl;
        for (; i < intervals.size(); ++i) {
            auto& interval = intervals[i];
            if (!ans.empty() && ans.back()[1] >= interval[0]) {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }else{
                ans.push_back(interval);
            }
        }

        return ans;
    }
};
