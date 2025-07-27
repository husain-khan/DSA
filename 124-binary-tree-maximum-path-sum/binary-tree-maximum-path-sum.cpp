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
    int maxPathSum(TreeNode* root) {
        int sum=0;
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
     int solve(TreeNode* node, int &maxi) {
        if (node == nullptr) return 0;

        // Recursive call to left and right, and discard negative paths by using max(0, ...)
        int leftsum = max(0, solve(node->left, maxi));
        int rightsum = max(0, solve(node->right, maxi));

        // Current path sum including both left and right child and the current node
        int currentSum = leftsum + rightsum + node->val;

        // Update global maximum if currentSum is higher
        maxi = max(maxi, currentSum);

        // Return max gain if we go through one child (for recursion/parent node)
        return node->val + max(leftsum, rightsum);
    }
};