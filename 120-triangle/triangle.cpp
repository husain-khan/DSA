    class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int ans=INT_MAX;
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
         for(int col=0;col<n;col++){
            ans=min(ans,helper(n-1,col,triangle,dp));
         }
        return ans;
        }

        int helper(int row,int col,vector<vector<int>> &triangle,vector<vector<int>>&dp){

            if(row==0 && col==0){
                return triangle[0][0];
            }    

            if(col>triangle[row].size()-1||col<0||row<0){
                return INT_MAX;
            }
            if(dp[row][col]!=-1){
                return dp[row][col];
            }
            
         dp[row][col]=triangle[row][col] + min(helper(row-1,col-1,triangle,dp), helper(row-1,col,triangle,dp));

          return dp[row][col];
        }
    };