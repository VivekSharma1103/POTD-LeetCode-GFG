class Solution {
  public:
    int minCoins(vector<int>& coins, int target_sum) {
    const int INF = 1e9;  // A large value to represent impossible cases
    vector<int> dp(target_sum + 1, INF);
    dp[0] = 0; // Base case: 0 coins needed for sum 0

    for (int coin : coins) {
        for (int j = coin; j <= target_sum; ++j) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    return (dp[target_sum] == INF) ? -1 : dp[target_sum];
    }
};
