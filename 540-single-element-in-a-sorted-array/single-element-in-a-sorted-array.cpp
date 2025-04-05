class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Force mid to be even-indexed
            if (mid % 2 == 1) mid--;
            
            if (nums[mid] == nums[mid + 1]) {
                // Target is in right half
                low = mid + 2;
            } else {
                // Target is in left half (including current mid)
                high = mid;
            }
        }
        return nums[low];
    }
};
