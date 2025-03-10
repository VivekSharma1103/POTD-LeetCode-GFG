class Solution {
  private:
    int m, n;
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i >= m) return (n - j);
        if (j >= n) return (m - i);
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if (s1[i] == s2[j]) {
            ans = solve(s1, s2, i + 1, j + 1, dp);
        } else {
            int rem = 1 + solve(s1, s2, i, j + 1, dp);
            int ins = 1 + solve(s1, s2, i + 1, j, dp);
            int rep = 1 + solve(s1, s2, i + 1, j + 1, dp);
            ans = min({rem, ins, rep});
        }
        
        return dp[i][j] = ans;
    }
    
  
    int approach_1(string &s1, string &s2) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(s1, s2, 0, 0, dp);
    }


  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        m = s1.length(), n = s2.length();
        
         return approach_1(s1, s2);
        
       
    }
};
