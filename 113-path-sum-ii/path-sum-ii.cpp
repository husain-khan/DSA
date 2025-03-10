class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        
        dfs(root, targetSum, 0, path, result);
        
        return result;
    }
    
    void dfs(TreeNode* node, int targetSum, int currentSum, vector<int>& path, vector<vector<int>>& result) {
        if (node == nullptr) {
            return;
        }
        
        currentSum += node->val;
        path.push_back(node->val);
        
        if (node->left == nullptr && node->right == nullptr && currentSum == targetSum) {
            result.push_back(path);
        }
        
        dfs(node->left, targetSum, currentSum, path, result);
        dfs(node->right, targetSum, currentSum, path, result);
        
        path.pop_back(); // Backtrack
    }
};
