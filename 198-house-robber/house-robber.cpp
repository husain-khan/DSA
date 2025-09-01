class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<int>dp(n,-1);
        int sum=0;
       return helper(i,n,nums,dp,sum);
        
    }

    int helper(int i,int n,vector<int>nums,vector<int>&dp,int sum){
       if(i>=n){
        return sum;
       }
       if(dp[i]!=-1){
        return dp[i];
       }
       int choose=helper(i+2,n,nums,dp,sum)+nums[i];

       int notchoose=helper(i+1,n,nums,dp,sum);
       dp[i]=max(choose,notchoose);
       return dp[i];
    }
};