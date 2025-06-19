class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dQ;  // store indices

        if (k == 0 || n == 0) return ans;

        // Process first k elements (first window)
        for (int i = 0; i < k; i++) {
            // Remove smaller elements from back
            while (!dQ.empty() && nums[dQ.back()] < nums[i]) {
                dQ.pop_back();
            }
            dQ.push_back(i);
        }
        ans.push_back(nums[dQ.front()]);  // max of first window

        // Process rest of the elements
        for (int i = k; i < n; i++) {
            // Remove indices out of this window
            while (!dQ.empty() && dQ.front() <= i - k) {
                dQ.pop_front();
            }

            // Remove smaller elements from back
            while (!dQ.empty() && nums[dQ.back()] < nums[i]) {
                dQ.pop_back();
            }

            dQ.push_back(i);

            // Current max is at front
            ans.push_back(nums[dQ.front()]);
        }

        return ans;
    }
};
