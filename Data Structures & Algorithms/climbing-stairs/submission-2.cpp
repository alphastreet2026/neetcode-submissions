class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2){
            return n;
        }
        
        int prev1 = 1;
        int prev2 = 2;

        // 0 1 2 3 (1111, 211, 121, 22, 112)
        int curr = 0;
        for (int i = 3; i <=n; ++i){
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return curr;
    }
};
