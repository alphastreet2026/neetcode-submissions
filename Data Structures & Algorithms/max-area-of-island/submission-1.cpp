class Solution {
    void dfs(int r, int c, int& count, vector<vector<int>>& grid) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return;
        }

        grid[r][c] = 0;
        ++count;
        dfs(r + 1, c, count, grid);
        dfs(r - 1, c, count, grid);
        dfs(r, c + 1, count, grid);
        dfs(r, c - 1, count, grid);
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(i, j, count, grid);
                    maxCount = max(count, maxCount);
                }
            }
        }

        return maxCount;
    }
};
