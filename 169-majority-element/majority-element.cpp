class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int count=n/2;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            int countinhash=mp[nums[i]];
            if(countinhash>count){
                ans=max(ans,nums[i]);
            }
              
        }
        return ans;
    }
};