class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex; // Stores the last occurrence of each character
        
        // Step 1: Store last occurrence of each character
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i]] = i;
        }

        vector<int> partitions;
        int start = 0, end = 0;

        // Step 2: Iterate and determine partitions
        for (int i = 0; i < s.length(); i++) {
            end = max(end, lastIndex[s[i]]); // Expand the partition

            if (i == end) { // If we reach the partition end
                partitions.push_back(end - start + 1);
                start = i + 1; // Start new partition
            }
        }

        return partitions;
    }
};
