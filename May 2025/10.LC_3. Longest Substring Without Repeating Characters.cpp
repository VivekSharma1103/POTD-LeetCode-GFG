class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ans;
        int max_len = 0;
        int left = 0;
                
          for (int right = 0; right < s.length(); right++) {
            while (ans.count(s[right])) {
                ans.erase(s[left]);
                left++;
            }
            ans.insert(s[right]);
            max_len = max(max_len, right - left + 1);
        }
        

        return max_len;
    }
};
