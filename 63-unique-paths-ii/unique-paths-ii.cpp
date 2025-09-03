class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid[0].size();
        int m=obstacleGrid.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,obstacleGrid,dp);
    }

    int helper(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(m<0||n<0 ||grid[m][n]==1){
            return 0;
        }
        if(m==0&&n==0){
            if(grid[m][n]!=1){
               return 1;
            }  
            else{
                return 0;
            } 
        }
        if(dp[m][n]!=-1 &&grid[m][n]!=1){
            return dp[m][n];
        }
         dp[m][n]=helper(m-1,n,grid,dp)+helper(m,n-1,grid,dp);
        return dp[m][n];
    }
};
