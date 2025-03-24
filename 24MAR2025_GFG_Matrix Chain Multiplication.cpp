class Solution {
public:
    vector<vector<int>> dp;

    int mcm(vector<int>& arr, int i, int j) {
        if (i >= j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int minCost = INT_MAX;
        for (int k = i; k < j; k++) {
            int cost = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            minCost = min(minCost, cost);
        }

        return dp[i][j] = minCost;
    }

    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n, vector<int>(n, -1));
        return mcm(arr, 1, n - 1);
    }
};
