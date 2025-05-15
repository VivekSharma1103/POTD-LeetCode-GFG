class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;

        int n = words.size();

        // Always include the first word
        result.push_back(words[0]);

        // Track the group of the last selected word
        int lastGroup = groups[0];

        for (int i = 1; i < n; ++i) {
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);
                lastGroup = groups[i];
            }
        }

        return result;
    }
};
