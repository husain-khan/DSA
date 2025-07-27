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

        // Only take positive paths; if negative, consider as 0
        int left = max(0, solve(node->left, maxi));
        int right = max(0, solve(node->right, maxi));

        // Max path through the current node
        int currentPathSum = node->val + left + right;

        // Update global maximum
        maxi = max(maxi, currentPathSum);

        // Return the max gain from either left or right plus current node
        return node->val + max(left, right);
    }
};