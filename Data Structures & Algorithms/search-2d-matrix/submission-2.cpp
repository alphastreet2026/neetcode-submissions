class Solution {
    pair<int, int> index(int index, int n) {
        int r = index / n;
        int c = index % n;
        return {r, c};
    }

   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int lo = 0;
        int hi = m * n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            auto [r, c] = index(mid, n);
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] < target) {
                lo = mid + 1;
            } else if (matrix[r][c] > target) {
                hi = mid - 1;
            }
        }

        return false;
    }
};
