class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));  // Initialize an empty matrix
        int count = 1;  // Counter for filling the matrix
        int top = 0, bottom = n - 1, left = 0, right = n - 1;  // Boundaries
        
        while (top <= bottom && left <= right) {
            // Fill from left to right
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = count++;
            }
            top++;
            
            // Fill from top to bottom
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = count++;
            }
            right--;
            
            // Fill from right to left
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = count++;
                }
                bottom--;
            }
            
            // Fill from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = count++;
                }
                left++;
            }
        }
        
        return matrix;
    }
};
