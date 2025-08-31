class Solution {
public:
    
    int climbStairs(int n) {
      int i=0;
      vector<int>dp(n+1,-1);
      return helper(i,dp,n);
    }
    
    int helper(int i,vector<int> &dp,int n){                                                                                       
        if(i>=n){
        if(i==n)return 1;
        return 0;
      }

        if(dp[i]!=-1){return dp[i];}
        int one=helper(i+1,dp,n);
        int two=helper(i+2,dp,n);
        dp[i]=one+two;
        return dp[i];
    }
};