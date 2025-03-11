class Solution {
  public:
    int countWays(int n) {
        // your code here
         if (n <= 1) return 1;
    
    int prev2 = 1, prev1 = 1;
    
    for (int i = 2; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
    }
};
