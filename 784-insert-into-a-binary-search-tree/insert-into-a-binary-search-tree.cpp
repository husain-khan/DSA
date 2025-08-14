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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=root;
        if(root==nullptr){
            TreeNode* temp=new TreeNode(val);
             root=temp;
            return root;
        }

        while(true){
            if(node->val>val){
                if(node->left!=nullptr){
                    node=node->left;
                }
                else{
                    TreeNode* temp=new TreeNode(val);
                    node->left=temp;
                    break;
                }
            }
            else{
                if(node->right!=nullptr){
                    node=node->right;
                }
                else{
                    TreeNode* temp=new TreeNode(val);
                    node->right=temp;
                    break;
                }
            }
        }
        return root;
    }
};