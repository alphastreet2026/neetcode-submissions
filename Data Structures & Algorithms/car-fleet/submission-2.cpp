class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // 3 4x 10 3
        int n = speed.size();
        vector<pair<int, double>> fleet;

        for (int i = 0; i < n; ++i) {
            int p = position[i];
            int s = speed[i];
            double time = static_cast<double>(target - p) / s;
            fleet.emplace_back(p, time);
        }
        ranges::sort(fleet, greater<pair<int, double>>());
        stack<double> ms;

        for (auto& [pos, time] : fleet) {
            if (!ms.empty() && time <= ms.top()) {
                continue;
            }
            ms.push(time);
        }
        return ms.size();
    }
    // 1 1 12 7 3
};
