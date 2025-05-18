class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> transitions;
    vector<vector<int>> validColorings;

    // Generate all valid colorings for a single column
    void generateColorings(int m, vector<int>& current, vector<vector<int>>& all) {
        if (current.size() == m) {
            all.push_back(current);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (current.empty() || current.back() != color) {
                current.push_back(color);
                generateColorings(m, current, all);
                current.pop_back();
            }
        }
    }

    int colorTheGrid(int m, int n) {
        // Step 1: Generate all valid column colorings
        vector<int> current;
        generateColorings(m, current, validColorings);

        int sz = validColorings.size();
        transitions.resize(sz);

        // Step 2: Build transitions: valid pairs of column colorings
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                bool compatible = true;
                for (int k = 0; k < m; ++k) {
                    if (validColorings[i][k] == validColorings[j][k]) {
                        compatible = false;
                        break;
                    }
                }
                if (compatible) {
                    transitions[i].push_back(j);
                }
            }
        }

        // Step 3: DP
        vector<long long> dp(sz, 1); // base case: 1 way to start with any valid coloring
        for (int col = 1; col < n; ++col) {
            vector<long long> newDp(sz, 0);
            for (int i = 0; i < sz; ++i) {
                for (int next : transitions[i]) {
                    newDp[next] = (newDp[next] + dp[i]) % MOD;
                }
            }
            dp = newDp;
        }

        // Sum all ways
        long long total = 0;
        for (long long val : dp) total = (total + val) % MOD;
        return (int)total;
    }
};
