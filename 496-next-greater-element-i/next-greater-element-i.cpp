class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i) {
            int num = nums1[i];
            int pos = -1;
            // Find the position of num in nums2
            for (int j = 0; j < m; ++j) {
                if (nums2[j] == num) {
                    pos = j;
                    break;
                }
            }
            // Use a stack to find the next greater element to the right
            stack<int> st;
            for (int j = pos + 1; j < m; ++j) {
                // Push elements onto the stack
                st.push(nums2[j]);
            }
            while (!st.empty()) {
                if (st.top() > num) {
                    ans[i] = st.top();
                }
                st.pop();
            }
        }
        return ans;
    }
};
