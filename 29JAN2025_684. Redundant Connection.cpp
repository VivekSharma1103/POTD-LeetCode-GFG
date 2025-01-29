class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& adj, int u, int v, vector<bool>& visited) {
        if (u == v) return true;
        visited[u] = true;
        for (int &ne : adj[u]) {
            if (visited[ne]) continue;
            if (dfs(adj, ne, v, visited)) return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            vector<bool> visited(n + 1, false);  

            // If both nodes exist in the graph and DFS finds a path, it's a cycle
            if (adj.count(u) && adj.count(v) && dfs(adj, u, v, visited)) {
                return edges[i];
            }

            // Otherwise, add the edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
