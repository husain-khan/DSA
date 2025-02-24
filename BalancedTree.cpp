class Solution {
public:
    int getHeight(TreeNode* node) {
        if (!node) return -1; // Base case: empty tree has height -1
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true; // Base case: empty tree is balanced

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return (abs(leftHeight - rightHeight) <= 1) &&
               isBalanced(root->left) &&
               isBalanced(root->right);
    }
};
