class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];  // only one house
    vector<int>dp1(n,-1);
    vector<int>dp2(n,-1);
    // Case 1: Rob from 0 to n-2
    int case1 = helper(0,n-2,nums,dp1);

    // Case 2: Rob from 1 to n-1
    int case2 = helper(1,n-1,nums,dp2);

    return max(case1, case2);
}

    int helper(int i,int n,vector<int>&nums,vector<int>&dp){
       if(i>n){
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