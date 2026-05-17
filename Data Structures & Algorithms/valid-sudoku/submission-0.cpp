class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use boolean array to store the availability of cell. Each row and columns and 3x3 box
        // Contains 9 values -> Boolean array to contains those. Start with all false.
        // As we traverse through 9x9 -> Any cell that is already visited will considered invalid.
        vector<vector<bool>> rows (board.size(), vector<bool> (board[0].size(), false));
        vector<vector<bool>> cols (board.size(), vector<bool> (board[0].size(), false));
        vector<vector<bool>> boxes(board.size(), vector<bool> (board[0].size(), false));
        // Boxes are indexed as 3*i + j. the second index col is indexed as the number filled.
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') continue;
                if (rows[i][board[i][j] - '0' - 1] || cols[j][board[i][j] - '0' - 1] || boxes[3*(i / 3) + (j / 3)][board[i][j] - '0' - 1]) return false;
                rows[i][board[i][j] - '0' - 1] = true;
                cols[j][board[i][j] - '0' - 1] = true;
                boxes[3*(i / 3) + (j / 3)][board[i][j] - '0' - 1] = true;
            }
        }
        return true;
    }
};
