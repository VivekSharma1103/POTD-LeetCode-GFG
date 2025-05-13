class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        long long freq[2][26] = {}; // Toggle between freq[0] and freq[1]
        
        // Initialize freq[0] with initial character counts
        for (char c : s) {
            freq[0][c - 'a']++;
        }

        int cur = 0, next = 1;
        for (int step = 0; step < t; ++step) {
            // Reset the next array
            fill(freq[next], freq[next] + 26, 0);

            for (int i = 0; i < 26; ++i) {
                if (i == 25) {
                    // 'z' -> 'a' + 'b'
                    freq[next][0] = (freq[next][0] + freq[cur][25]) % MOD;
                    freq[next][1] = (freq[next][1] + freq[cur][25]) % MOD;
                } else {
                    // c -> next char
                    freq[next][i + 1] = (freq[next][i + 1] + freq[cur][i]) % MOD;
                }
            }

            // Swap cur and next
            swap(cur, next);
        }

        // Sum all characters in final freq[cur]
        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + freq[cur][i]) % MOD;
        }

        return (int)result;
    }
};
