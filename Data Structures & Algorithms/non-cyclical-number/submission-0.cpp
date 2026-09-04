class Solution {
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

   public:
    bool isHappy(int n) {
        unordered_set<int> s;

        while (n != 1) {
            // cout << n << endl;
            if (!s.insert(n).second) {
                return false;
            }

            n = getSum(n);
        }
        return true;
    }
};
