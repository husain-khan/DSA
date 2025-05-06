class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        // Precompute isPalindrome[i][j]
        for (int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2) isPalindrome[i][j] = true;
                    else isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                }
            }
        }

        // Initialize dp
        for (int i = 0; i < n; ++i) {
            if (isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = i; // max cuts
                for (int j = 1; j <= i; ++j) {
                    if (isPalindrome[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
