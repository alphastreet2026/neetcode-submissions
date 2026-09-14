class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 1   2  3 4 5
        // 3   4  5 1 2
        // -2 -2 -2 3 3

        // 1, 2, 3, 4
        // 2, 2, 4, 1
        // -1 0 -1  3

        int n = gas.size();
        

        int sum = 0;
        int startId = 0;
        int balance = 0;
        for (int i = 0; i < n; ++i) {
            balance += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (balance < 0){
                startId = (i+1) % n;
                balance = 0; 
            }
        }
        return sum < 0 ? -1 : startId;
    }
};