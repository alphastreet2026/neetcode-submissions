class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using Pair = pair<int, int>;
        vector<vector<Pair>> g(n+1);

        for (const auto& edge : times){
            g[edge[0]].emplace_back(edge[2], edge[1]);
        }

        vector<int> distTo(n+1, INT_MAX);
        distTo[k] = 0;
        
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        pq.push({0, k});

        while (!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if (distTo[u] < d){
                continue;
            }

            for (auto& [weight, v] : g[u]){
                int dist = distTo[u] + weight;
                if (distTo[v] > dist){
                    pq.emplace(dist, v);
                    distTo[v] = dist;
                }
            }
        }

        int time = INT_MIN;
        for (int i =1; i <= n; ++i){
            if (distTo[i] == INT_MAX){
                return -1;
            }
            time = max(time, distTo[i]);
        }
        return time;
    }
};
