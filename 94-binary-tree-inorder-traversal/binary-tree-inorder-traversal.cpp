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
    
    vector<int> inorderTraversal(TreeNode* node) {
     vector<int> ans;
     traversal(node,ans);
     return ans;
    }
    void traversal(TreeNode* node, vector<int>&ans){
           if(node==NULL){
            return;
        }
        
        traversal(node->left,ans);
        ans.push_back(node->val);
        traversal(node->right,ans);
    }
};