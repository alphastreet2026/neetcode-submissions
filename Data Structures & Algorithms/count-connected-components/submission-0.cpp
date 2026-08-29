class Solution {
    vector<bool> marked;

    void dfs(int v, vector<vector<int>>& g) {
        marked[v] = true;
        for (int w : g[v]) {
            if (!marked[w]) {
                dfs(w, g);
            }
        }
    }

   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& edge : edges) {
            int v = edge[0];
            int w = edge[1];
            g[v].push_back(w);
            g[w].push_back(v);
        }

        marked = vector<bool>(n);
        int cc = 0;
        for (int v = 0; v < n; ++v) {
            if (!marked[v]) {
                dfs(v, g);
                ++cc;
            }
        }

        return cc;
    }
};
