
class TrieNode {
public:
    TrieNode* left;  // Represents bit 0
    TrieNode* right; // Represents bit 1
    
    TrieNode() {
        left = right = nullptr;
    }
};

class Solution {
public:
    int maxXor(vector<int> &arr) {
        TrieNode* root = new TrieNode();
        int maxXor = 0;
        
        // Insert all numbers in the Trie
        for (int num : arr) {
            TrieNode* node = root;
            for (int i = 31; i >= 0; i--) { // 32 bits for each integer
                int bit = (num >> i) & 1;
                if (bit == 0) {
                    if (node->left == nullptr) node->left = new TrieNode();
                    node = node->left;
                } else {
                    if (node->right == nullptr) node->right = new TrieNode();
                    node = node->right;
                }
            }
        }

        // Calculate the maximum XOR
        for (int num : arr) {
            TrieNode* node = root;
            int currentXor = 0;
            for (int i = 31; i >= 0; i--) { // 32 bits for each integer
                int bit = (num >> i) & 1;
                if (bit == 0) {
                    if (node->right != nullptr) {
                        currentXor |= (1 << i);
                        node = node->right;
                    } else {
                        node = node->left;
                    }
                } else {
                    if (node->left != nullptr) {
                        currentXor |= (1 << i);
                        node = node->left;
                    } else {
                        node = node->right;
                    }
                }
            }
            maxXor = max(maxXor, currentXor);
        }

        return maxXor;
    }
};
