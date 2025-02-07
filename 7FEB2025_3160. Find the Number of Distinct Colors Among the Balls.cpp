class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result;
        unordered_map<int, int> freq; 
        unordered_map<int, int> assignedColor; 
        int count = 0;

        for(int i = 0; i < n; i++) {
            int x = queries[i][0];
            int y = queries[i][1];

            
            if (assignedColor.find(x) != assignedColor.end()) {
                int prevColor = assignedColor[x];
                freq[prevColor]--;
                if (freq[prevColor] == 0) count--; 
            }

           
            assignedColor[x] = y;
            freq[y]++;
            if (freq[y] == 1) count++; 

            result.push_back(count);
        }
        return result;
    }
};
