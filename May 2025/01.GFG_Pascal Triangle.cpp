
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        const int MOD = 1e9 + 7;
        vector<int> row(n, 1);  // Initialize with 1s

        for (int i = 2; i < n; ++i) {
            // Update from right to left to avoid overwriting
            for (int j = i - 1; j > 0; --j) {
                row[j] = (row[j] + row[j - 1]) % MOD;
            }
        }

        return row;
    }
};
