class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vec;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                vec.push_back(grid[i][j]);
            }
        }

      
        sort(vec.begin(), vec.end());

        int n = vec.size();
        int mid = vec[n / 2];
        int count = 0;

        for(int i = 0; i < vec.size(); i++){
            int diff = abs(vec[i] - mid);
            if(diff % x != 0) return -1;
            count += diff / x;
        }

        return count;
    }
};
