class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        if (val.size() != wt.size()) return 0; // Ensure valid input sizes
        
        vector<int> dp(W + 1, 0); 
        
        for (int i = 0; i < wt.size(); i++) { // Start from 0
            for (int j = W; j >= wt[i]; j--) {
                dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
            }
        }
        
        return dp[W];
    }
};
