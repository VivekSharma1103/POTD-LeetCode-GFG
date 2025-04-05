class Solution {
public:
    int countIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> directions = {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0},
            {1, 1}, {-1, -1}, {-1, 1}, {1, -1}
        };

        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto p = q.front();
                        int x = p.first;
                        int y = p.second;
                        q.pop();

                        for (auto dir : directions) {
                            int nx = x + dir[0];
                            int ny = y + dir[1];

                            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                                grid[nx][ny] == 'L' && !visited[nx][ny]) {
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};
