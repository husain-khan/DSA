class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = helper(coins, amount, 0, dp);
        return ans >= INT_MAX ? -1 : ans;
    }

    int helper(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (amount < 0 || idx >= coins.size()) return INT_MAX;

        if (dp[idx][amount] != -1) return dp[idx][amount];

        int pick = helper(coins, amount - coins[idx], idx, dp);
        if (pick != INT_MAX) pick = 1 + pick;

        int nopick = helper(coins, amount, idx+1, dp);

        return dp[idx][amount] = min(pick, nopick);
    }
};
