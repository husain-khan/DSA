#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        for (int i = 0; i < n; ++i) {
            // If we encounter a '0', we need to flip
            if (nums[i] == 0) {
                // Check if flipping is possible
                if (i + 2 >= n) {
                    return -1; // Not enough elements to flip
                }
                // Flip the current element and the next two
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++operations; // Increment operation count
            }
        }

        return operations;
    }
};