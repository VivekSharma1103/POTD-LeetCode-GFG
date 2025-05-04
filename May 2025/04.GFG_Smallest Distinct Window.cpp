class Solution {
  public:
    int findSubString(string& str) {
        int n = str.size();
        unordered_set<char> unique_chars(str.begin(), str.end());
        int distinct_count = unique_chars.size();

        unordered_map<char, int> window_freq;
        int start = 0, min_len = n + 1, count = 0;

        for (int end = 0; end < n; end++) {
            window_freq[str[end]]++;

            if (window_freq[str[end]] == 1)
                count++; // new unique character added to window

            // Try to shrink the window from the start
            while (count == distinct_count) {
                if (end - start + 1 < min_len)
                    min_len = end - start + 1;

                window_freq[str[start]]--;
                if (window_freq[str[start]] == 0)
                    count--; // one unique char removed

                start++;
            }
        }

        return min_len;
    }
};
