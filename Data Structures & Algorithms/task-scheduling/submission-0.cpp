class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);

        int maxFreq = 0;
        for (char task : tasks){
            freq[task - 'A']++;
            maxFreq = max(maxFreq, freq[task - 'A']);
        }

        int maxFreqCnt = 0;
        for (int cnt : freq){
            if (cnt == maxFreq){
                ++maxFreqCnt;
            }
        }

        int time = (maxFreq -1) * (n+1) + maxFreqCnt;
        return max(time, (int)tasks.size());
        
    }
};
