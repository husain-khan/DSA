class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If the middle element is smaller than the next one, 
            // the peak must be on the right side
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } 
            // Otherwise, the peak must be on the left side
            else {
                right = mid;
            }
        }
        
        // At this point, left and right are the same, and this index is a peak
        return left;
    }
};
