class BSTIterator {
private:
    stack<TreeNode*> st;
    
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        
        if (top->right) {
            pushLeft(top->right);
        }
        
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
};
