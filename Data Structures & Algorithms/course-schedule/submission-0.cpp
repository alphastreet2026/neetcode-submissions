class Solution {
    enum State { NOT_VISITED, VISITING, VISITED };

    vector<State> marked;

    bool dfs(int v, vector<vector<int>>& g) {
        marked[v] = VISITING;

        for (int w : g[v]) {
            if (marked[w] == VISITING) {
                return false;
            }
            if (marked[w] == NOT_VISITED) {
                if (!dfs(w, g)) {
                    return false;
                }
            }
        }

        marked[v] = VISITED;
        return true;
    }

   public:
    bool canFinish(int num, vector<vector<int>>& preqs) {
        vector<vector<int>> g(num);
        marked = vector<State>(num, NOT_VISITED);

        for (auto& p : preqs) {
            if (p[0] == p[1]) {
                return false;
            }
            g[p[1]].push_back(p[0]);
        }

        for (int v = 0; v < num; ++v) {
            if (marked[v] == NOT_VISITED) {
                if (!dfs(v, g)) {
                    return false;
                }
            }
        }
        return true;
    }
};
