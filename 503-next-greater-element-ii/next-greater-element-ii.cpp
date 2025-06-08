class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;  // stack stores indices

        // Double the vector by concatenation (optional, but you can simulate with modulo)
        nums.insert(nums.end(), nums.begin(), nums.end());

        for (int i = 2 * n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (i < n) {
                if (!st.empty()) {
                    ans[i] = nums[st.top()];
                }
            }

            st.push(i);
        }

        return ans;
    }
};
