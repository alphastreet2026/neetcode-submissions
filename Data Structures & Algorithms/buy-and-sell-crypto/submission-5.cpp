class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        int currentMin = INT_MAX;
        
        for (int i=0; i <n; ++i) {
            currentMin = min(currentMin, prices[i]);
            maxProfit = max(maxProfit, prices[i] - currentMin);
        }
        
        return maxProfit;
    }
};
