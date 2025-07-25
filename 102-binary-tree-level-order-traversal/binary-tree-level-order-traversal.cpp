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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> Q;
        
        Q.push(root);

        while(!Q.empty()){
         vector<int> temp;
           int size=Q.size();
            for(int i=0;i<size;i++){
                TreeNode *node=Q.front();
                Q.pop();
                temp.push_back(node->val);
                if(node->left!=NULL)Q.push(node->left);
                if(node->right!=NULL)Q.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};