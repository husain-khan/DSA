class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // col -> (row -> multiset of node values)
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> Q; // node, {row, col}

        Q.push({root, {0, 0}});

        while (!Q.empty()) {
            auto [node, pos] = Q.front();
            Q.pop();
            int row = pos.first;
            int col = pos.second;

            // Store value in map
            nodes[col][row].insert(node->val);

            // Push children with updated row/col
            if (node->left)
                Q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                Q.push({node->right, {row + 1, col + 1}});
        }

        // Now build output from sorted map
        vector<vector<int>> ans;
        for (auto &colPair : nodes) {
            vector<int> colVals;
            for (auto &rowPair : colPair.second) {
                colVals.insert(colVals.end(), rowPair.second.begin(), rowPair.second.end());
            }
            ans.push_back(colVals);
        }
        return ans;
    }
};
