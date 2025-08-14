class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        vector<int> ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(mpp.count(nums[i])){
                mpp[nums[i]]++;
            }
            else{
                mpp[nums[i]]=1;
            }
        }
        for(auto it:mpp){
            if(it.second>n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};