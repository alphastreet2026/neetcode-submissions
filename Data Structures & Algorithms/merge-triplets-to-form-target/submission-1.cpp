class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        vector<bool> targets(3);
        for (auto & triplet : triplets){
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]){
                continue;
            }

            if (triplet[0] == target[0]){
                targets[0] = true;
            }
            if (triplet[1] == target[1]){
                targets[1] = true;
            }
            if (triplet[2] == target[2]){
                targets[2] = true;
            }
            
        }
        return targets[0] && targets[1] && targets[2];
    }
};
