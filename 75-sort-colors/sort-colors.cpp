class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1, current = 0;
        
        while (current <= right) {
            if (nums[current] == 0) {
                std::swap(nums[left], nums[current]);
                left++;
                current++;
            } else if (nums[current] == 2) {
                std::swap(nums[right], nums[current]);
                right--;
            } else {
                current++;
            }
        }
    }
};
