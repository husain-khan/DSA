#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> ple(n), nle(n), pge(n), nge(n);
        stack<int> s;

        // Previous Less Element (PLE)
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] > nums[i]) s.pop();
            ple[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();

        // Next Less or Equal Element (NLE)
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            nle[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();

        // Previous Greater Element (PGE)
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] < nums[i]) s.pop();
            pge[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();

        // Next Greater or Equal Element (NGE)
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] <= nums[i]) s.pop();
            nge[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long minSum = 0, maxSum = 0;
        for (int i = 0; i < n; ++i) {
            // For minimums
            long long left = i - ple[i];
            long long right = nle[i] - i;
            minSum += (long long)nums[i] * left * right;

            // For maximums
            long long left2 = i - pge[i];
            long long right2 = nge[i] - i;
            maxSum += (long long)nums[i] * left2 * right2;
        }
        return maxSum - minSum;
    }
};
