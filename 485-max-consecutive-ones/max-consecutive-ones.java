class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int len=0;
        int l=0,r=0;
        while(r<nums.length)
        {
            if(nums[r]==1)
            {
                len=Math.max(len,r-l+1);
                r++;
            }
            else
            {
                r++;
                l=r;
            }
        }
        return len;
    }
}