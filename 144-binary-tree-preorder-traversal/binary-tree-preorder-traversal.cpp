/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* node) {
     vector<int> ans;
     traversal(node,ans);
     return ans;
    }
void traversal(TreeNode* node, vector<int>& ans) {
    if (node == nullptr) return;
    stack<TreeNode*> st;
    st.push(node);
    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        // Push right child first so left is processed first
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
}


};