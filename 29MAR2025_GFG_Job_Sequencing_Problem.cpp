
class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
    
        sort(jobs.rbegin(), jobs.rend());
        
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> slots(maxDeadline + 1, -1);
        
        int totalJobs = 0;
        int totalProfit = 0;
        
       
        for (int i = 0; i < n; i++) {
            int profit = jobs[i].first;
            int dead = jobs[i].second;
            
            
            for (int j = dead; j > 0; j--) {
                if (slots[j] == -1) {
                    slots[j] = i;
                    totalProfit += profit;
                    totalJobs++;
                    break;
                }
            }
        }
        
        return {totalJobs, totalProfit};
    }
};
