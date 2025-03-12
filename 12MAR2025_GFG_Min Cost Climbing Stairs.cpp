class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
         int n = cost.size();
    vector<int> dp(n);

    // Base cases
    dp[0] = cost[0];
    dp[1] = cost[1];

    // Build the DP table
    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    // Minimum cost to reach the top
    return min(dp[n - 1], dp[n - 2]);
    }
};
