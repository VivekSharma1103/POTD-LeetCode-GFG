class Solution {
  public:
  
    // Helper function that returns a pair:
    // first -> max sum including this node
    // second -> max sum excluding this node
    pair<int, int> dfs(Node* node) {
        if (!node) return {0, 0};
        
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        
        // If we include this node, we cannot include its immediate children
        int include = node->data + left.second + right.second;
        
        // If we exclude this node, we can include or exclude its children
        int exclude = max(left.first, left.second) + max(right.first, right.second);
        
        return {include, exclude};
    }
    
    // Main function
    int getMaxSum(Node *root) {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }
};
