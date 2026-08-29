class Solution {
    void addToQ(int r, int c, queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return;
        }

        grid[r][c] = 0;
        q.push({r, c});
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    addToQ(i, j, q, grid);
                    int count = 0;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        ++count;
                        addToQ(r + 1, c, q, grid);
                        addToQ(r - 1, c, q, grid);
                        addToQ(r, c + 1, q, grid);
                        addToQ(r, c - 1, q, grid);
                    }
                    maxCount = max(count, maxCount);
                }
            }
        }

        return maxCount;
    }
};
