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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        solve(root,q,ans);
        return ans; 
    }

    vector<vector<int>> solve(TreeNode* node,queue<TreeNode*> &q,vector<vector<int>>&ans){
        if(node==nullptr){
            return ans;
        }
        bool flag=false;
        
        while(!q.empty()){
           
            vector<int>temp;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *curr=q.front(); 
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=nullptr)q.push(curr->left);
                if(curr->right!=nullptr)q.push(curr->right);
            }
             if (flag) {
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};