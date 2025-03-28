class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int Q = queries.size();
        vector<int> result(Q, 0);

        vector<pair<int, int>> qIdx(Q);
        for (int i = 0; i < Q; i++) {
            qIdx[i] = {queries[i], i};
        }
        sort(qIdx.begin(), qIdx.end()); // Sort queries in ascending order

        // Priority queue to process grid values in increasing order
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int points = 0;
        
        for (auto &[val, idx] : qIdx) {
            while (!pq.empty() && pq.top().first < val) {
                auto [value, cell] = pq.top(); pq.pop();
                int i = cell.first, j = cell.second;
                points++;
                
                for (auto &[di, dj] : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                        pq.push({grid[ni][nj], {ni, nj}});
                        visited[ni][nj] = true;
                    }
                }
            }
            result[idx] = points;
        }
        
        return result;
    }
};
