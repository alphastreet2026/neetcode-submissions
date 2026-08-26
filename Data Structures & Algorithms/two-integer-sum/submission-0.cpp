class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // ranges::sort(nums);
        unordered_map<int, vector<int>> map;
        for (int i=0; i < nums.size(); ++i){
            map[nums[i]].push_back(i);
        }

        vector<int> ans;
        for (int i=0; i < nums.size(); ++i){
            int other = target - nums[i];
            if (map.contains(other)){
                if (nums[i] == other && map[other].size() == 1){
                    continue;
                }else if (nums[i] == other && map[other].size() > 1){
                    ans.push_back(map[other][0]);
                    ans.push_back(map[other][1]);
                    break;
                }

                ans.push_back(min(i, map[other].front()));
                ans.push_back(max(i, map[other].front()));
                break;
            }
            
        }
        return ans;

    }
};
