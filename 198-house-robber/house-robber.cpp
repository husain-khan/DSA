class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<int>dp(n,-1);

       return helper(i,n,nums,dp);
        
    }

    int helper(int i,int n,vector<int>nums,vector<int>&dp){
       if(i>=n){
        return 0;
       }
       if(dp[i]!=-1){
        return dp[i];
       }
       int choose=helper(i+2,n,nums,dp)+nums[i];

       int notchoose=helper(i+1,n,nums,dp);
       dp[i]=max(choose,notchoose);
       return dp[i];
    }
};