class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Mark border 'O' regions
        for (int i = 0; i < rows; i++) {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            dfs(board, 0, j);
            dfs(board, rows - 1, j);
        }
        
        // Replace remaining 'O's with 'X's and restore marked 'O' regions
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }
        
        board[i][j] = 'T'; // Mark as not surrounded
        
        dfs(board, i - 1, j); // Up
        dfs(board, i + 1, j); // Down
        dfs(board, i, j - 1); // Left
        dfs(board, i, j + 1); // Right
    }
};
