class Solution {
  public:
    int lis(vector<int>& nums) {
        // code here
           int n = nums.size();
        if (n == 0) return 0;

    vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
    }
};
