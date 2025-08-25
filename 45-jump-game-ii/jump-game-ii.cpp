class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int jumps=0;

        while(r<nums.size()-1){
           int farthest=0;
            for(int x=l;x<=r;x++){
                farthest=max(farthest,x+nums[x]);
                
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};