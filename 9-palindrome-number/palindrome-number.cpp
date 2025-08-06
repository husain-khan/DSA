class Solution {
public:
    bool isPalindrome(int x) {
        bool ans=true;
        vector<int> nums;
        if(x<0) return false;
        while(x/10!=0){
            int t=x%10;
            nums.push_back(t);
            x=x/10;
        }
        nums.push_back(x);

        int low=0;
        int high=nums.size()-1;

        while(low<high){
            if(nums[low]!=nums[high]){
                ans=false;
                break;
            }
            low++;
            high--;
        }
       
       return ans;
    }
};