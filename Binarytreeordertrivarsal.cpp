class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {}; // If the tree is empty, return an empty vector

        vector<vector<int>> result; // Vector to store the result
        queue<TreeNode*> q; // Queue for level order traversal
        q.push(root); // Start with the root node

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            vector<int> levelValues; // Vector to store node values at the current level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); // Dequeue a node
                q.pop(); // Remove the node from the queue

                levelValues.push_back(node->val); // Add the node's value to the level's vector

                if (node->left) q.push(node->left); // Enqueue the left child if it exists
                if (node->right) q.push(node->right); // Enqueue the right child if it exists
            }

            result.push_back(levelValues); // Add the level's vector to the result
        }

        return result; // Return the level order traversal result
    }
};
