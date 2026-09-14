class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // 1 2 2 3 3 4 4 5
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        ranges::sort(hand);
        unordered_map<int, int> freq;
        for (int num : hand) {
            freq[num]++;
        }

        int groupId = 0;

        for (int i = 0; i < n; ++i) {
            int num = hand[i];
            if (freq[num] == 0) {
                continue;
            }
            
            int gs = 0;
            for (int g = 0; g < groupSize; ++g) {
                if (freq[num] == 0) {
                    return false;
                }
                freq[num]--;
                ++num;
            }
        }
        for (auto& [_, count] : freq) {
            if (count > 0) {
                return false;
            }
        }
        return true;
    }
};
