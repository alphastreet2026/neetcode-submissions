class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // (row / 3) * 3 + (col / 3)
        unordered_map<int, unordered_set<int>> rowMap;
        unordered_map<int, unordered_set<int>> colMap;
        unordered_map<int, unordered_set<int>> sqMap;

        for (int r = 0; r < 9; ++r){
            for (int c = 0; c < 9; ++c){
                
                if (!isdigit(board[r][c])){
                    continue;
                }
                if (!rowMap[r].insert(board[r][c]).second){
                    return false;
                }
                if (!colMap[c].insert(board[r][c]).second){
                    return false;
                }
                int sqId = (r/3)*3 + (c/3);
                if (!sqMap[sqId].insert(board[r][c]).second){
                    return false;
                }
            }
        }

        return true;
    }
};
