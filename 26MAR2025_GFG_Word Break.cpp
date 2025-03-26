class Solution {
public:
    unordered_set<string> st;
    int n;
    vector<int> memo;
    
    bool solve(int idx, string &s) {
       
        if (idx == n) return true;
        
        
        if (memo[idx] != -1) return memo[idx];
        
       
        int maxWordLen = 0;
        for (const string& word : st) {
            maxWordLen = max(maxWordLen, (int)word.length());
        }
        
       
        for (int l = 1; l <= min(maxWordLen, n - idx); l++) {
            string temp = s.substr(idx, l);
            
        
            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                memo[idx] = 1;
                return true;
            }
        }
        
        
        memo[idx] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
        
        if (wordDict.empty()) return false;
        
    
        memo = vector<int>(n, -1);
        
        
        for (string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(0, s);
    }
};
