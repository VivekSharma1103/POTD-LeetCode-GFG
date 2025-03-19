class Solution {
public:
    vector<vector<vector<int>>> dp;

    int profit_maxx(int i, int k, int buy, vector<int>& prices) {
        if (k == 0 || i >= prices.size()) {
            return 0;
        }

        if (dp[i][k][buy] != -1) {
            return dp[i][k][buy];
        }

        int profit = 0;
        if (buy) {
            // Option to buy or skip
            profit = max(-prices[i] + profit_maxx(i + 1, k, 0, prices), 
                         profit_maxx(i + 1, k, 1, prices));
        } else {
            // Option to sell or skip
            profit = max(prices[i] + profit_maxx(i + 1, k - 1, 1, prices), 
                         profit_maxx(i + 1, k, 0, prices));
        }

        return dp[i][k][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // Initialize the DP table with -1 (indicating uncomputed states)
        dp.resize(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return profit_maxx(0, k, 1, prices);
    }
};
