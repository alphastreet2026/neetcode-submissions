class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int k) {
        
        int lo = 0;
        int hi = numbers.size()-1;

        while (lo < hi){
            if (numbers[lo] + numbers[hi] > k){
                --hi;
            } else if (numbers[lo] + numbers[hi] < k){
                ++lo;
            }else{
                return {lo+1, hi+1};
            }

        }
        return {};
    }
};
