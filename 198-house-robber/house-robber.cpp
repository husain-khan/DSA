class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        int sum=0;
        vector<int>dp(n,-1);
        int ans=INT_MIN;
       return helper(idx,nums,n,dp);
    }

    int helper(int i,vector<int>&nums,int n,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

       int take= helper(i+2,nums,n,dp)+nums[i];
       int notake= helper(i+1,nums,n,dp);
       dp[i]=max(take,notake);
        return dp[i];
    }
};