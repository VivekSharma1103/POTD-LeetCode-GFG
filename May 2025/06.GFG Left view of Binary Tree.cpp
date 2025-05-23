class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> result;
        if (root == NULL) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                Node* current = q.front();
                q.pop();
                
                // First node of this level
                if (i == 0) {
                    result.push_back(current->data);
                }

                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }

        return result;
    }
};
