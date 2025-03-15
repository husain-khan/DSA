#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canRobWithCapability(vector<int>& nums, int k, int capability) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; ) {
            if (nums[i] <= capability) {
                count++;
                i += 2; // Skip the adjacent house
            } else {
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canRobWithCapability(nums, k, mid)) {
                result = mid; // Update result to the minimum feasible capability
                right = mid - 1; // Try smaller capabilities
            } else {
                left = mid + 1; // Try larger capabilities
            }
        }

        return result;
    }
};
