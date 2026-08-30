#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(int v, int parent, const vector<vector<int>>& g, vector<bool>& marked) {
        marked[v] = true;

        for (int w : g[v]) {
            if (!marked[w]) {
                if (!dfs(w, v, g, marked)) {
                    return false;
                }
            }
            else if (w != parent) {
                return false; // Cycle discovered!
            }
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Condition 1: A valid tree MUST have exactly n - 1 edges
        // if (edges.size() != n - 1) {
        //     return false;
        // }

        vector<vector<int>> g(n);
        vector<bool> marked(n, false);
        for (const auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        // Start DFS from node 0. If it finds a cycle, it's not a tree.
        if (!dfs(0, -1, g, marked)) {
            return false;
        }

        // Condition 2: Ensure the graph is fully connected.
        // Since edges == n-1, checking if all nodes are marked guarantees connectivity.
        for (bool visited : marked) {
            if (!visited) return false;
        }

        return true;
    }
};
