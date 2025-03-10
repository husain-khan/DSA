class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesHelper(1, n);
    }
    
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        vector<TreeNode*> result;
        
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
            vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);
            
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
};
