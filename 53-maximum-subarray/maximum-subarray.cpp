class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int ans=INT_MIN;
        int left=0;
        int right=0;
       while(right<n){
           sum=sum+nums[right];
           ans=max(sum,ans);
           if(sum<0){
            sum=0;
            left=right+1;
           }
            right++;
        }
        return ans;
    }
};