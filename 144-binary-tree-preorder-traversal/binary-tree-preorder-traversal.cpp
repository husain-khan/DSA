class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> stack;
        stack.push(root);
        
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            
            // Visit the current node
            result.push_back(node->val);
            
            // Push the right child first so it's visited after the left child
            if (node->right != nullptr) stack.push(node->right);
            if (node->left != nullptr) stack.push(node->left);
        }
        
        return result;
    }
};
