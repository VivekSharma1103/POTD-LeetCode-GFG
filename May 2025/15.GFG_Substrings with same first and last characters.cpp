class Solution {
  public:
    int countSubstring(string &s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int count = 0;

        // Apply the formula for each character
        for (int i = 0; i < 26; i++) {
            count += (freq[i] * (freq[i] + 1)) / 2;
        }

        return count;
    }
};
