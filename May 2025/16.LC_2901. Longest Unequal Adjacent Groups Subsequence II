class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1); // dp[i] = longest path ending at i
        vector<int> prev(n, -1); // prev[i] = previous index in the path

        // Try every pair of indices (i, j)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].size() == words[j].size() &&
                    hammingDistance(words[i], words[j]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }

        // Find index with maximum path length
        int maxLen = 0, lastIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the path
        vector<string> result;
        while (lastIndex != -1) {
            result.push_back(words[lastIndex]);
            lastIndex = prev[lastIndex];
        }

        reverse(result.begin(), result.end());
        return result;
    }

private:
    int hammingDistance(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i])
                ++diff;
        }
        return diff;
    }
};
