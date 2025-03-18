#include <vector>
#include <algorithm>

class Solution {
public:
    int longestNiceSubarray(std::vector<int>& nums) {
        int ans = 0;
        int mask = 0; // To keep track of the bitwise OR of the current window
        int j = 0;    // Start index of the window
        
        for (int i = 0; i < nums.size(); ++i) {
            // While there's a conflict with the current number
            while (mask & nums[i]) {
                mask ^= nums[j]; // Remove the number at index j from mask
                j++;             // Move the start index forward
            }
            
            // Update maximum length found
            ans = std::max(ans, i - j + 1);
            
            // Include current number in mask
            mask |= nums[i];
        }
        
        return ans; // Return the maximum length found
    }
};
