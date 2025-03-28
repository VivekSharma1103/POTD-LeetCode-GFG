class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // Step 1: Create a vector of pairs (finish time, start time)
        vector<pair<int, int>> activities;
        for (int i = 0; i < start.size(); i++) {
            activities.push_back({finish[i], start[i]});
        }
        
        // Step 2: Sort by finish time
        sort(activities.begin(), activities.end());
        
        int count = 0;
        int last = -1;
        
        // Step 3: Select activities
        for (auto &act : activities) {
            int s = act.second;
            int f = act.first;
            if (s > last) {  // Pick if start time > last selected finish time
                last = f;
                count++;
            }
        }
        
        return count;
    }
};
