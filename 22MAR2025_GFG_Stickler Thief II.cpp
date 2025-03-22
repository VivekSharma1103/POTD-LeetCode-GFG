class Solution {
    int solve(vector<int>& arr, int start, int end, vector<int>& dp) {
        if (start > end) return 0;
        if (dp[start] != -1) return dp[start];

        int pick = arr[start] + solve(arr, start + 2, end, dp);
        int nopick = solve(arr, start + 1, end, dp);

        return dp[start] = max(pick, nopick);
    }
  
  public:
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = solve(arr, 0, n - 2, dp1); // Exclude last element
        int case2 = solve(arr, 1, n - 1, dp2); // Exclude first element

        return max(case1, case2);
    }
};
