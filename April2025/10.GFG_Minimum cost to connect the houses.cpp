class Solution {
public:
    int minCost(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;

        int totalCost = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;
            // Find the unvisited node with min distance
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            visited[u] = true;
            totalCost += minDist[u];

            // Update distance to MST for remaining nodes
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], cost);
                }
            }
        }

        return totalCost;
    }
};
