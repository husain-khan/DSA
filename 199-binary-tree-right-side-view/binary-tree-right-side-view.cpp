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
    vector<int> rightSideView(TreeNode* root) {
         queue<pair<TreeNode*,pair<int,int>>> Q;
         vector<int> fans;
        vector<vector<int>>ans;
        if(root==nullptr){
            return fans;
        }
         Q.push({root, {0, 0}});

        while(!Q.empty()){
            vector<int>temp;
            int siz=Q.size();
            for(int i=0;i<siz;i++){
            auto it=Q.front();
            TreeNode* frontnode=it.first;
            temp.push_back(frontnode->val);
            int row=it.second.first;
            int column=it.second.second;
            Q.pop();
            if(frontnode->left!=NULL)Q.push({frontnode->left,{row+1,column-1}});
            if(frontnode->right!=NULL)Q.push({frontnode->right,{row+1,column+1}});

            }
            ans.push_back(temp);
        }

      for(int i=0;i<ans.size();i++){
        int t=ans[i].size()-1;
        fans.push_back(ans[i][t]);
      }


       return fans; 
    }
};