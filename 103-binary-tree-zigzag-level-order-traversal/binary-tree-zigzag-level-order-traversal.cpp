class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        solve(root, q, ans);
        return ans; 
    }

    vector<vector<int>> solve(TreeNode* node, queue<TreeNode*>& q, vector<vector<int>>& ans) {
        bool flag = false;

        while (!q.empty()) {
            int levelSize = q.size(); // Important: fix size before the loop
            vector<int> temp;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front(); 
                q.pop();
                temp.push_back(curr->val);
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }

            if (flag) {
                reverse(temp.begin(), temp.end());
            }

            ans.push_back(temp);
            flag = !flag; // flip after each level
        }

        return ans;
    }
};
