class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount + 1);
        dp[0] = 0;

        for (int coin : coins){
            for (int a = coin; a <= amount; ++a){
                dp[a] = min(dp[a], dp[a - coin] + 1);
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
