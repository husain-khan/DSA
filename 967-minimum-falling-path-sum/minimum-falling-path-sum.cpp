class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        dp.assign(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;
        for (int col = 0; col < n; col++) {
            ans = min(ans, dfs(0, col, matrix));
        }
        return ans;
    }

    int dfs(int row, int col, vector<vector<int>>& matrix) {
        if (col < 0 || col >= n) return INT_MAX;

        if (row == n - 1) return matrix[row][col];

        if (dp[row][col] != INT_MAX) return dp[row][col];

        int down = dfs(row + 1, col, matrix);
        int left = dfs(row + 1, col - 1, matrix);
        int right = dfs(row + 1, col + 1, matrix);

        dp[row][col] = matrix[row][col] + min(down, min(left, right));
        return dp[row][col];
    }
};