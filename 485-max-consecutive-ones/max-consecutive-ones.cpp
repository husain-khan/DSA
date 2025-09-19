class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int tempcount=0;
        int i=0;
        int ans=0;
        while(i<nums.size()){
           
           while(i < nums.size() && nums[i]==1){
                  tempcount++;
                  ans=max(ans,tempcount);
              i++;
           }
           
           tempcount=0;

            while(i < nums.size() && nums[i]==0){
                i++;
            }
        }
        return ans;
    }
};