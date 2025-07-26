class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkBalance(root).second;
    }

private:
    // Returns {height, isBalanced}
    pair<int, bool> checkBalance(TreeNode* node) {
        if (!node) return {0, true};

        auto left = checkBalance(node->left);
        auto right = checkBalance(node->right);

        int height = 1 + max(left.first, right.first);
        bool balanced = left.second && right.second && abs(left.first - right.first) <= 1;

        return {height, balanced};
    }
};
