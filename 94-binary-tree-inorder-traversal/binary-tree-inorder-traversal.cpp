class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            // Go to the leftmost node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Process the node
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            // Visit the right subtree
            curr = curr->right;
        }

        return ans;
    }
};
