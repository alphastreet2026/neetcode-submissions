#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 1. Sort intervals by their END times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        // 2. Keep track of the end time of the last accepted interval
        int prevEnd = intervals[0][1];

        // 3. Iterate through the rest of the intervals
        for (size_t i = 1; i < intervals.size(); ++i) {
            // If the current interval starts BEFORE the previous one ends, it overlaps
            if (intervals[i][0] < prevEnd) {
                count++; // We must remove this interval
            } else {
                // No overlap, accept this interval and update the end tracker
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};
