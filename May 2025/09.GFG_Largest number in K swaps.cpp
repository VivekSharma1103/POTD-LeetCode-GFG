class Solution {
public:
    string maxNum;

    void solve(string &s, int k, int idx) {
        if (k == 0 || idx == s.length()) return;

        char maxDigit = s[idx];
        for (int i = idx + 1; i < s.length(); i++) {
            if (s[i] > maxDigit) {
                maxDigit = s[i];
            }
        }

        // If the current digit is already the biggest, skip swap
        if (maxDigit == s[idx]) {
            solve(s, k, idx + 1);
            return;
        }

        // Try all possible swaps with maxDigit
        for (int i = idx + 1; i < s.length(); i++) {
            if (s[i] == maxDigit) {
                swap(s[idx], s[i]);
                if (s > maxNum) maxNum = s;
                solve(s, k - 1, idx + 1);
                swap(s[idx], s[i]); // backtrack
            }
        }
    }

    string findMaximumNum(string s, int k) {
        maxNum = s;
        solve(s, k, 0);
        return maxNum;
    }
};
