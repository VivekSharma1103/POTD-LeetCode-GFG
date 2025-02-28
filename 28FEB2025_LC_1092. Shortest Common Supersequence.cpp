class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> t(m + 1, vector<int>(n + 1));

        // Fill DP table using LCS-based logic
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0)
                    t[i][j] = j;
                else if (j == 0)
                    t[i][j] = i;
                else if (s1[i - 1] == s2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = 1 + min(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        // Construct the Shortest Common Supersequence
        string result = "";
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result.push_back(s1[i - 1]);
                i--;
                j--;
            } else if (t[i - 1][j] < t[i][j - 1]) {
                result.push_back(s1[i - 1]);
                i--;
            } else {
                result.push_back(s2[j - 1]); // Fix: use `s2` instead of `s1`
                j--;
            }
        }

        // Append remaining characters from `s1` or `s2`
        while (i > 0) {
            result.push_back(s1[i - 1]);
            i--;
        }
        while (j > 0) {
            result.push_back(s2[j - 1]); // Fix: use `s2` instead of `s1`
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
