class Solution {
public:
    bool canPartition(vector<int>& arr) {
         int n=arr.size();
         int sum=0;
         for(int i=0;i<n;i++){
            sum=sum+arr[i];
         }
        if(sum%2!=0) return false;
        int x=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        return helper(arr,x,n,0,dp)==1?true:false;
    }
    
    int helper(vector<int>&arr,int target,int n,int idx,vector<vector<int>>&dp){
        
        if(target==0){
                return 1;
            }
        if(idx==n ||target<0){
            return 0;
        }
        if(dp[idx][target]!=-1){
            return  dp[idx][target];
        }
        
        int choose=helper(arr,target-arr[idx],n,idx+1,dp);
        int nochoose=helper(arr,target,n,idx+1,dp);
        
        dp[idx][target]=max(choose,nochoose);
        return dp[idx][target]; 
    }
};