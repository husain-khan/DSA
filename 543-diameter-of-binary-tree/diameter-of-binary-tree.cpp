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
    int diameterOfBinaryTree(TreeNode* root) {
       int maxi=0;
        // diameterOfBinaryTree(root)
        help(root,maxi);
        return maxi;
    }

    int help(TreeNode* node,int &maxi){
        if(node==nullptr){
            return 0;
        }
        int l=help(node->left,maxi);
        int r=help(node->right,maxi);
         maxi=max(maxi,l+r);
        return 1 + max(l, r);
    }
};