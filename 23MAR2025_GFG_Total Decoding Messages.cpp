class Solution {
public:
    int countWays(string digits) {
        int n = digits.size();
        if (n == 0 || digits[0] == '0') return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case for empty string
        dp[1] = (digits[0] != '0') ? 1 : 0;

        for (int i = 2; i <= n; i++) {
            // Single digit decoding
            if (digits[i - 1] >= '1' && digits[i - 1] <= '9') {
                dp[i] += dp[i - 1];
            }
            // Two-digit decoding
            int twoDigit = stoi(digits.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};
