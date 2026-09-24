class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lo = 0;
        int hi = n-1;
        int loMax = 0;
        int hiMax = 0;

        int w = 0;
        while (lo <= hi){
            if (height[lo] < height[hi]){
                if (height[lo] >= loMax){
                    loMax = height[lo];
                }else{
                    w += loMax - height[lo];
                }
                ++lo;
            }
            else{
                if (height[hi] >= hiMax){
                    hiMax = height[hi];
                }else{
                    w += hiMax - height[hi];
                }
                --hi;
            }
        }
        
        return w;
    }

    int trap2(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n);
        prefix[0] = height[0];

        vector<int> suffix(n);
        suffix[n-1] = height[n-1];

        for (int i = 1; i < n; ++i){
            prefix[i] = max(prefix[i-1], height[i]);
        }

        for (int i = n-2; i >= 0; --i){
            suffix[i] = max(suffix[i+1], height[i]);
        }   

        int w = 0;
        for (int i = 1; i < n; ++i){
            w += min(prefix[i], suffix[i]) - height[i];
        }
        return w;
    }
};
