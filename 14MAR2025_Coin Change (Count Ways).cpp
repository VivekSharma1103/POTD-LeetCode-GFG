class Solution {
public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        
        // Base case: number of ways to make sum 0 with any number of coins is 1 (by taking none)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                // Exclude current coin
                dp[i][j] = dp[i - 1][j];
                
                // Include current coin (if j >= coins[i - 1])
                if (j >= coins[i - 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        
        return dp[n][sum];
    }
};
