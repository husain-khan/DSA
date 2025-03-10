class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> visited;
        
        return cloneNode(node, visited);
    }
    
    Node* cloneNode(Node* node, unordered_map<Node*, Node*>& visited) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        
        Node* clone = new Node(node->val);
        visited[node] = clone;
        
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneNode(neighbor, visited));
        }
        
        return clone;
    }
};
