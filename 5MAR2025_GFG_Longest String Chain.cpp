class Solution {
public:
    int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int maxLen = 0;

        for (const string &word : words) {
            int best = 1;  // Start with 1 instead of 0
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(prev)) {
                    best = max(best, dp[prev] + 1);
                }
            }
            dp[word] = best;
            maxLen = max(maxLen, best);
        }

        return maxLen;
    }
};
