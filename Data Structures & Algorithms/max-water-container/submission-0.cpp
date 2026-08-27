class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxVol = 0;
        int lo = 0;
        int hi = heights.size() -1;

        while (lo < hi){
            int vol = (hi -lo) * min(heights[lo], heights[hi]);
            maxVol = max(vol, maxVol);
            if (heights[lo] < heights[hi]){
                ++lo;
            }else{
                --hi;
            }
        }
        return maxVol;
    }
};
