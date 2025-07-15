#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        // Step 1: Compute prefix sum array
        vector<int> prefixsum(n, 0);
        prefixsum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + nums[i];
        }

        // Step 2: Iterate through all subarrays and find number of subarrays with sum k
        for (int start = 0; start < n; ++start) {
            for (int end = start; end < n; ++end) {
                int currSum;
                
                // Use if-else for clarity
                if (start == 0) {
                    currSum = prefixsum[end];
                } else {
                    currSum = prefixsum[end] - prefixsum[start - 1];
                }

                if (currSum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
