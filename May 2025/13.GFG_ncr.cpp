class Solution {
public:
    int nCr(int n, int r) {
        if (r > n) return 0;

        int C[101][101] = {0};

        // Base case: C[i][0] = 1
        for (int i = 0; i <= n; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= std::min(i, r); ++j) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }

        return C[n][r];
    }
};
