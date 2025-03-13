class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;  // To store all valid board configurations
        vector<string> board(n, string(n, '.'));  // Initialize an empty chessboard
        vector<bool> columns(n, false);  // Tracks if a column is occupied
        vector<bool> diag1(2 * n - 1, false);  // Tracks major diagonals (/)
        vector<bool> diag2(2 * n - 1, false);  // Tracks minor diagonals (\)
        
        backtrack(0, n, board, columns, diag1, diag2, solutions);
        return solutions;
    }
    
private:
    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& columns, vector<bool>& diag1,
                   vector<bool>& diag2, vector<vector<string>>& solutions) {
        if (row == n) {  // Base case: all queens are placed
            solutions.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (columns[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue;  // Skip if placing a queen here is invalid
            }
            
            // Place the queen
            board[row][col] = 'Q';
            columns[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
            
            // Recur to place the next queen
            backtrack(row + 1, n, board, columns, diag1, diag2, solutions);
            
            // Backtrack: remove the queen and reset state
            board[row][col] = '.';
            columns[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }
};
