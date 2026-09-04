class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> res(temps.size());
        stack<int> ms;
        
        for (int i= 0; i < temps.size(); ++i){
            while (!ms.empty() && temps[i] > temps[ms.top()]) {
                int left = ms.top();
                ms.pop();
                res[left] = i - left;
            }
            ms.push(i);
        } 
        return res;
    }
};
