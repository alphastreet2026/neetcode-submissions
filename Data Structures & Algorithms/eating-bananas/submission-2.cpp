class Solution {
    int time(vector<int>& piles, int speed) {
        int total = 0;
        for (int pile : piles) {
            total += ((pile + speed - 1) / speed);
        }
        return total;
    }

   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ranges::sort(piles);
        int n = piles.size();

        if (h == n) {
            return piles[n - 1];
        }

        int lo = 1;
        int hi = piles[n - 1];

        // int bestSpeed = piles[n - 1];
        while (lo < hi) {
            int speed = lo + (hi - lo) / 2;
            int eatingTime = time(piles, speed);
            if (eatingTime > h) {
                lo = speed + 1;
            } else {
                hi = speed;
                // bestSpeed = min(bestSpeed, speed);
            }
        }
        return hi;
    }
};
