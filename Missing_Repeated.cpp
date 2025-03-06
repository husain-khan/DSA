class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int s = m * n;

        vector<int> answer; // To store missing and repeated values
        vector<bool> checker(s, false); // To track presence

        int repeatedValue = -1; // Variable to store repeated value

        for (int i = 0; i < n; i++) { // Iterate rows
            for (int j = 0; j < m; j++) { // Iterate columns
                int temp = grid[i][j];
                if (temp > s || temp <= 0) {
                    continue; // Ignore values outside the range
                }
                if (checker[temp - 1] == false) {
                    checker[temp - 1] = true; // Mark as present
                } else {
                    repeatedValue = temp; // Store repeated value
                }
            }
        }

        // Find missing values
        for (int i = 0; i < s; i++) {
            if (checker[i] == false) {
                answer.push_back(i + 1); // Store missing value
            }
        }

        if (repeatedValue != -1) {
            answer.insert(answer.begin(), repeatedValue); // Add repeated value to the start of answer
        }

        return answer;
    }
};
