class Solution {
public:
    vector<long long> dp; 
    
    long long findpoints(int index, vector<vector<int>>& questions, int n) {
        if (index >= n) return 0; 
        if (dp[index] != -1) return dp[index]; 
        
  
        long long take = questions[index][0] + findpoints(index + questions[index][1] + 1, questions, n);
        
       
        long long skip = findpoints(index + 1, questions, n);
        
        return dp[index] = max(take, skip); 
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.assign(n, -1);  
        return findpoints(0, questions, n); 
    }
};
