class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
        dist[0][0][0] = 0;
        pq.emplace(0, 0, 0, 0);

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!pq.empty()) {
            auto [time, x, y, parity] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) {
                return time;
            }

            if (time > dist[x][y][parity]) continue;

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int move_duration = (parity == 0) ? 1 : 2;
                    int arrival_time = max(time, moveTime[nx][ny]) + move_duration;
                    int next_parity = 1 - parity;
                    if (arrival_time < dist[nx][ny][next_parity]) {
                        dist[nx][ny][next_parity] = arrival_time;
                        pq.emplace(arrival_time, nx, ny, next_parity);
                    }
                }
            }
        }

        return -1; // Should not reach here
    }
};

