class Solution {
  public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        // Map to store the cloned nodes
        unordered_map<Node*, Node*> mp;

        // Call the recursive DFS function
        return dfs(node, mp);
    }

  private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        // If the node is already cloned, return it
        if (mp.find(node) != mp.end()) return mp[node];

        // Clone the current node
        Node* clone = new Node(node->val);
        mp[node] = clone;

        // Recursively clone all the neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, mp));
        }

        return clone;
    }
};
