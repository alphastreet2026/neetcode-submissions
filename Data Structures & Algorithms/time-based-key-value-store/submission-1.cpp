class TimeMap {
    using Value = pair<int, string>;

    unordered_map<string, vector<Value>> tMap;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { tMap[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        if (!tMap.contains(key)) {
            return "";
        }
        auto& values = tMap[key];
        if (values.empty()) {
            return "";
        }

        int lo = 0;
        int hi = values.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (values[mid].first <= timestamp) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        // cout << "lo=" << lo << " hi=" << hi << endl;
        if (lo == 0){
            return "";
        }
        return values[hi-1].second;
    }
};
