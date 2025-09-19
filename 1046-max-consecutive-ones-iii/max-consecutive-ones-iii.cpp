class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zerocount=0;
        int onecount=1;
        int i=0;
        int left=0;
        int ans=0;
        while(i<nums.size()){
          if(nums[i]==0)zerocount++;

            if(zerocount>k){
                while(nums[left]!=0){
                    left++;
                }
                left++;
                zerocount--;
            }
                ans=max(ans,i-left+1);
            i++;
        }
        return ans;
    }
};