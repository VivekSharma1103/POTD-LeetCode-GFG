class Solution {
  public:
    void dfs(Node* root, vector<int>& currentPath, vector<vector<int>>& result) {
        if (root == NULL) return;

        // Add current node to the path
        currentPath.push_back(root->data);

        // If it's a leaf node, store the path
        if (root->left == NULL && root->right == NULL) {
            result.push_back(currentPath);
        } else {
            // Recursively visit left and right children
            dfs(root->left, currentPath, result);
            dfs(root->right, currentPath, result);
        }

        // Backtrack: remove the current node from the path
        currentPath.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> currentPath;
        dfs(root, currentPath, result);
        return result;
    }
};
