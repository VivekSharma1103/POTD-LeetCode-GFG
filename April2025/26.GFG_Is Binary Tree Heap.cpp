class Solution {
  public:
    bool isHeap(Node* root) {
        if (!root) return true;

        queue<Node*> q;
        q.push(root);
        bool nullSeen = false;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Left child check
            if (curr->left) {
                if (nullSeen || curr->data < curr->left->data)
                    return false;
                q.push(curr->left);
            } else {
                nullSeen = true;
            }

            // Right child check
            if (curr->right) {
                if (nullSeen || curr->data < curr->right->data)
                    return false;
                q.push(curr->right);
            } else {
                nullSeen = true;
            }
        }
        return true;
    }
};
