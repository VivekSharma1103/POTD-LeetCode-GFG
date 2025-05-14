class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int SIZE = 26;

    using Matrix = vector<vector<long long>>;

    // Multiply two matrices
    Matrix multiply(const Matrix &A, const Matrix &B) {
        Matrix result(SIZE, vector<long long>(SIZE, 0));
        for (int i = 0; i < SIZE; ++i) {
            for (int k = 0; k < SIZE; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < SIZE; ++j) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    // Fast exponentiation of matrix
    Matrix matrixPower(Matrix base, int exp) {
        Matrix result(SIZE, vector<long long>(SIZE, 0));
        // Identity matrix
        for (int i = 0; i < SIZE; ++i)
            result[i][i] = 1;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = multiply(result, base);
            base = multiply(base, base);
            exp /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Step 1: Frequency vector
        vector<long long> freq(SIZE, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Build transformation matrix
        Matrix trans(SIZE, vector<long long>(SIZE, 0));
        for (int c = 0; c < SIZE; ++c) {
            for (int j = 1; j <= nums[c]; ++j) {
                int nextChar = (c + j) % SIZE;
                trans[nextChar][c] = (trans[nextChar][c] + 1) % MOD;
            }
        }

        // Step 3: Raise the matrix to the power of t
        Matrix transT = matrixPower(trans, t);

        // Step 4: Multiply final matrix with initial frequency vector
        long long result = 0;
        for (int i = 0; i < SIZE; ++i) {
            long long sum = 0;
            for (int j = 0; j < SIZE; ++j) {
                sum = (sum + transT[i][j] * freq[j]) % MOD;
            }
            result = (result + sum) % MOD;
        }

        return static_cast<int>(result);
    }
};
